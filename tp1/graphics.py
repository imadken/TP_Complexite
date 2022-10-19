

import matplotlib.pyplot as plt


plt.xlabel("temps (ms)")
plt.ylabel("nombre des chiffres")


# xpoints => le temps

# ypoints => longeur des chiffres ,par exemple :  6 , 8 ,10 , 12


# dans la fonction plt.plot vous pouvez utiliser l'attribut linewidth ='xxx' pour changer l'epaisseur  


# algo1

xpoints = [1, 2, 6, 8]
ypoints = [6,8,10,12]
plt.plot(xpoints, ypoints,label='algo1')


# algo2
xpoints = [0, 7, 5, 2]
ypoints = [3, 8, 1, 10]
plt.plot(xpoints, ypoints,label='algo2')

# algo3
xpoints = [0, 7, 5, 2]
ypoints = [3, 8, 1, 10]
plt.plot(xpoints, ypoints,label='algo3')

# algo
xpoint4s = [0, 7, 5, 2]
ypoints = [3, 8, 1, 10]
plt.plot(xpoints, ypoints,label='algo4')

# algo5

xpoints = [0, 7, 5, 2]
ypoints = [0,0,0,0]
plt.plot(xpoints, ypoints,label='algo5')

# algo6
xpoints = [0, 0, 0, 0]
ypoints = [0,4,8,10]
plt.plot(xpoints, ypoints,label='algo6' )


plt.legend(loc="lower right")

plt.show()
