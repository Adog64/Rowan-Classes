Ar = 7.5E3
Gr = 2.0E3
Aom = 2.8E3
c = 8.0E4
slv = 2.0E4
pl = 7
ir = 0.1

pw = -c + Gr * (((1 + ir)**pl - 1)/((ir**2)*(((1+ir)**pl))) - (pl/(ir * (1+ir)**pl))) + (Ar - Aom)*(((1+ir)**pl)-1)/((ir*(1+ir)**pl)) + slv*(1+ir)**(-pl)
print(pw)