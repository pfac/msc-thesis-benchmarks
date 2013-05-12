#!/bin/sh

BIN_DIR="$1";
EXECS="malloc-memset calloc arma-zeros mat-loop mat-zeros";

for e in $EXECS;
do
	${BIN_DIR}/zeros-${e};
done;

