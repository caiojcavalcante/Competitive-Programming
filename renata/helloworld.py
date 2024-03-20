print("------------------------------- \n Selecione a operacao desejada:\n------------------------------- \n + para adicao\n- para subtracao\n * para multiplicacao\n / para divisao")
operacao = (input("------------------------------- \n qual operacao deseja usar?"))
if operacao == "+":
    print(f"Resultado da soma: {int(input('Primeiro numero:')) + int(input('Segundo numero:'))}")
if operacao == "-":
    print(f"Resultado da subtracao: {int(input('Primeiro numero:')) - int(input('Segundo numero:'))}")
if operacao == "*":
    print(f"Resultado da multiplicacao: {int(input('Primeiro numero:')) * int(input('Segundo numero:'))}")
if operacao == "/":
    print(f"Resultado da divisao: {int(input('Primeiro numero:')) / int(input('Segundo numero:'))}")