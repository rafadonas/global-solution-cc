# Título da tabela
print("A | B | C | D | F | G | X (Saída)")
print("--|---|---|---|---|---|----------")

# Itera sobre todas as 64 combinações de entrada
for a in range(2):
    for b in range(2):
        for c in range(2):
            for d in range(2):
                for f in range(2):
                    for g in range(2):
                        # Aplica a expressão lógica expandida
                        x = (a and c) or (a and b) or (b and d) or (b and f) or (a and f) or g
                        
                        # Imprime a linha da tabela
                        print(f"{a} | {b} | {c} | {d} | {f} | {g} |    {int(x)}")