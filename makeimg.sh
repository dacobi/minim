#!/bin/bash
./mountimg
rm mnt/MINIM/MINIM.PRG
rm mnt/MINIM/DAT/*
cp MINIM.PRG mnt/MINIM/
cp DAT/* mnt/MINIM/DAT/
umount mnt
rm MINIM/MINIM.PRG
rm MINIM/DAT/*
cp MINIM.PRG MINIM/
cp DAT/* MINIM/DAT/
rm minim.zip
7z a minim.zip MINIM minim.img
