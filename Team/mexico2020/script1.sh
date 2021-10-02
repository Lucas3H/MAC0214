#!/bin/bash

for i in {1..30}
do
	./f $i 30 >>out1 &
done