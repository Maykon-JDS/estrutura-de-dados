def busca_binaria(lista, item):
    baixo = 0
    alto = len(lista) - 1
    meio = int((baixo+alto)/2)
    
    if item == lista[meio]:
        return lista[meio]
    elif item < lista[meio]:
            for x in range(0,meio+1):
                lista.pop()
            return busca_binaria(lista, item)
    elif item > lista[meio]:
            for x in range(meio-1, alto):
                lista.pop(0)
            return busca_binaria(lista, item)

    return None

array = [1,2,3,4,5,9]
print(busca_binaria(array, 9))

