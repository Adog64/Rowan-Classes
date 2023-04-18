cap = 2.8E4
rev = 1.6E4
op = 6.6E3
slv = 1.3E4
lif = 3
ir = .04
reps = 2

pw = -cap + (rev - op) * ((((1+ir)**(reps * lif)) - 1)/(ir * (1+ir)**(lif*reps))) + (slv - cap)*(1 + ir)**(-lif) + slv*(1+ir)**(-reps*lif)
print(pw)