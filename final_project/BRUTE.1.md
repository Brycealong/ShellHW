%BRUTE(1) brute 1.0.5
%SylviaMei JialuWei Darcine Brycealong
%JUN 2022

# NAME
brute

# Synopsis
./brute FILENAME [-om overlap_minimum]

# DESCRIPTION
**brute** is a programme which can do APSA brutely.It outputs triplets indicating one overlap
for a suffix-string-number and a prefix-string-number with
the overlap length.

# OPTIONS
**-om**
:Set the minimum overlap.The default value is 10.

# Example
$./brute c_elegans_ests_200.fasta -om 5
37,85,545
41,74,6
47,80,6
48,80,6
60,80,6
66,85,545
67,85,545
109,168,7
130,80,6
146,80,6
151,74,6
152,74,6
157,74,6
167,74,6\
175,74,6

# EXIT VALUES
**0**
: Success

**-1**
: Input error
