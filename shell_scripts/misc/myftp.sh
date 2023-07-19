#!/bin/bash
# For downloading test file from ftp using "Here Document" concept

ftp -n ftp.ddu.ac.in <<BLOCKK
quote USER anonymous
quote PASS anonymous
cd pub
mget ebooklist.txt
bye
BLOCKK
grep java ebooklist.txt
echo "File downloaded successfully."
