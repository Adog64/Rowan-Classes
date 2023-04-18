f7s = {
    'ADD': 0,
    'SUB': 32,
    'AND': 0,
    'OR':  0,
    'XOR': 0,
    }
f3s = {
    'ADD': 0,
    'SUB': 0,
    'AND': 7,
    'OR':  6,
    'XOR': 4,
}
opcodes = {
    'ADD': 51,
    'SUB': 51,
    'AND': 51,
    'OR':  51,
    'XOR': 51,
}
print('Separate all arguments with spaces ONLY.')
for x in range(10):
    asm = input(f'I{x}: ').split()
    if asm[0] in ('ADD', 'SUB', 'XOR', 'OR', 'AND'):
        rd = eval(asm[1]) << 7
        rs1 = eval(asm[2]) << 15
        rs2 = eval(asm[3]) << 20
        f7 = f7s[asm[0]] << 25
        f3 = f3s[asm[0]] << 12
        opcode = opcodes[asm[0]]
        inst = f7 + rs2 + rs1 + f3 + rd + opcode
        bininst = bin(inst)
        bininst = bininst[:2] + '0'*(30-len(bininst)) + bininst[2:]
        hexinst = hex(inst)
        hexinst = hexinst[:2] + '0'*(7-len(hexinst)) + hexinst[2:]
        print(bininst)
        print(hexinst)