import pandas as pd
import numpy as np
import os
#import seaborn
import subprocess

cols = ["elemntos","objetivo","fza bruta","backtracking","dinamica","burta iterativa","back iteritavasuid"]

# proc = subprocess.Popen('cat Entradas/pruebaFacil.txt | ./TP1', stdout=subprocess.PIPE,shell = True)
# df = pd.DataFrame(columns = cols)
# df2 = pd.read_csv(proc.stdout, index_col = 0, header = None)
# print (pd.concat([df,df2]))

datos = open("Entradas/pruebaFacil.txt","r")

elementos = datos.read().splitlines()[1:] 

temp = open("Entradas/temp","w")

output = open("Entradas/output","w")

hasta = 20
objetivo = 45
reps = 50


for i in range(3,hasta):
	temp = open("Entradas/temp","w")
	temp.write(str(i) + " " + str(objetivo)+"\n")
	for j in elementos:
		temp.write(str(j)+"\n")


	temp = open("Entradas/temp","r")

	suma = np.zeros(shape=(reps,6),dtype=float)
	for k in range(reps):
		#proc = subprocess.Popen('cat Entradas/pruebaFacil.txt | ./TP1', stdout=subprocess.PIPE,shell = True)
		proc = subprocess.Popen('cat Entradas/temp | ./TP1', stdout=subprocess.PIPE,shell = True)
		out = proc.stdout.read()
		array = np.fromstring(out,dtype=float, sep=',')

		suma[k] = array

	mn = np.mean(suma,axis=0)

	error = np.std(suma[1:],axis=0)
	
	#df = pd.DataFrame(mn)
	#df.to_csv(output)

	np.savetxt(output,[mn],newline='\n',delimiter=',',fmt='%.6f')
	np.savetxt(output,[error],newline='\n',delimiter=',',fmt='%.6f')
	print mn
	print error	

	temp = open("Entradas/temp","w")

	temp.truncate(0)

os.remove("Entradas/temp")


