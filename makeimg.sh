#!/bin/bash
./mountimg
rm mnt/MINIM/MINIM.PRG
rm mnt/MINIM/DAT/*
cp MINIM.PRG mnt/MINIM/
cp DAT/* mnt/MINIM/DAT/
umount mnt
rm minim.zip
7z a minim.zip minim.img
