#!/usr/bin/python

n = 0

def setup():
	global n
	n = 100

def loop():
	global n
	n = n + 1
	if((n % 2) == 0):
		print(n)

setup()
while True:
	loop()
