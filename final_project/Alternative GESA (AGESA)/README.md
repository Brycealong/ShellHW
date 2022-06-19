# aapsp

For compile:
sh compile.sh

For run:
sh run.sh

To check output after running:
cat aapsp.out

In order to test results when om = 10 and .fasta file = 'c_elegans_ests_200.fasta':
First download `dataset.rar` and decompress it.

Then move the obtained Folder `dataset` into Folder `input` where only `strings32` is originally there.

After that, you need to edit run.sh:

find the last line which looks like: 
```
./aapsp -f input/strings32
``` 
and change it to:
```
./aapsp -f input/dataset/ -t 10
```
om is denoted by the integer after `-t`.
Also you are welcome to test other om as well.
