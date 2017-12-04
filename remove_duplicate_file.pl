#!/usr/bin/perl

# I wrote this script to remove duplicate downloaded music mp3 files
# in my music directory.

# Say there are some duplicate files like this:
# a.mp3, a(1).mp3, a(4).mp3
# this script can remove a(1).mp3 and a(4).mp3 files

use 5.014;
use strict;
use File::Basename;
use File::HomeDir;

my @file_name_lst;
my $cloud_music = File::HomeDir->my_home . "/Music/CloudMusic";

while (glob("$cloud_music/*.mp3")) {
    if (/(.*)\.mp3$/) {push @file_name_lst, basename($1)}
}

my %name_duplicate_dic;
my $reg = '(.*)(\(\d+\))+$';

for (@file_name_lst) {
    push @{$name_duplicate_dic{$_}}, $_;

    if (/$reg/) {push @{$name_duplicate_dic{$1}}, $_;}
}

for (@file_name_lst){
    my @tmp = @{$name_duplicate_dic{$_}};
    if (@tmp > 1) {
	for (grep /$reg/, @tmp) {
	    my $file = $cloud_music . "/$_.mp3";
	    if (-e $file) {
		say "deleting file: $file";
		# unlink $file or die "failed to delete $file";
	    }
	}
	say(join(', ', (grep /$reg/, @tmp)));
    }
}
