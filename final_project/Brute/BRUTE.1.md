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
11,16,476\
19,20,308\
20,19,308\
24,6,5\
33,62,615\
40,41,421\
41,40,421\
48,112,5\
51,33,537\
51,62,537\
51,63,537\
52,105,5\
63,33,576\
63,62,576\
70,37,6\
70,59,5\
70,85,5\
70,119,5\
70,124,5\
70,125,5\
70,147,6\
70,148,6\
70,153,6\
70,163,6\
70,171,6\
70,185,5\
76,40,5\
76,41,5\
76,43,6\
76,44,6\
76,56,6\
76,65,5\
76,89,5\
76,100,5\
76,126,6\
76,142,6\
76,149,5\
76,180,5\
76,181,5\
76,199,5\
76,203,5\
81,33,545\
81,62,545\
81,63,545\
155,156,495\
156,155,495\
159,14,5\
159,194,254\
164,105,7\
171,115,5\
194,14,5\
194,159,254

# EXIT VALUES
**0**
: Success

**-1**
: Input error
