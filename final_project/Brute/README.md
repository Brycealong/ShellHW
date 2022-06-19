# Brute APSP
## Compile
```
make
```
## Usage
```
./brute FILENAME [-om # overlap_minimum]
```
## man page
First check if `/usr/local/man` exists. If not:
```
sudo mkdir /usr/local/man/
```
then goes:
```
sudo mkdir /usr/local/man/man1/
sudo cp BRUTE.1 /usr/local/man/man1
sudo gzip /usr/local/man/man1/BRUTE.1
sudo mandb
```
(Always use `tab` key as your helper)
At last, we can check our manpage as usual:
```
man BRUTE
```
