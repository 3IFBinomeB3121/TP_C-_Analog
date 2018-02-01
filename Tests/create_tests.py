#!/usr/bin/python3
# -*- coding: utf-8 -*

import os

listFiles = os.listdir("./")
nbTests = 0

for fileName in listFiles:
	if "Test" in fileName:
		n = fileName.split("Test")[1]
		if n.isdigit() and int(n) > nbTests: 
			nbTests = int(n)

newDirectory = "Test" + str(nbTests+1)
os.mkdir(newDirectory)

os.chdir(newDirectory)

os.system("touch std.in")

commandLine = input("Command-line : ")
logFilePath = input("Localisation fichier de log : ")
description = input("Description : ") 
inputData = input("Contenu de l'entrée standard : ")

run = open("run", "w")
run.write(commandLine)
run.close()

desc = open("description", "w")
desc.write(description)
desc.close()

returnCode = open("returncode", "w")
returnCode.write("0")
returnCode.close()

if inputData != "":
	stdIn = open("std.in", "w")
	stdIn.write(inputData)
	stdIn.close()

logFile = commandLine.split(" ")[-1]
os.system("cp " + logFilePath + " " + logFile)

os.system(commandLine + "> std.out 2> stderr.out")

listFiles =  os.listdir("./")

print("\nCréation du " + newDirectory)

os.system("ls")

for filename in listFiles:
	if filename != logFile:
		file = open(filename, "r")
		print('\n' + filename + " : ")
		print(file.read())
		file.close()
	if ".dot" in filename:
                os.rename(filename, filename + ".outfile")

