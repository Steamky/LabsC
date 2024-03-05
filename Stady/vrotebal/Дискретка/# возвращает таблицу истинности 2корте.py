# возвращает таблицу истинности по кортежу значений функции 3 переменных
def truth_table_by_vec(v):
    assert(len(v) == 8)
    tt = {}
    i = 0
    for A in range(2):
        for B in range(2):
            for C in range(2):
                tt[A, B, C] = v[i]
                i += 1
    return tt

#v_maj = (0, 0, 0, 1, 0, 1, 1, 1)
#tt = truth_table_by_vec(v_maj)

# возвращает таблицу истинности по заданной функции 3 переменных
def truth_table_by_func(f):
    tt = {}
    for A in range(2):
        for B in range(2):
            for C in range(2):
                tt[A, B, C] = f(A, B, C)
    return tt

def f_maj(x, y, z):
    return x and y or x and z or y and z

def f(x, y, z):
    #return y | z & ~x
    #return ~x & y & z | x & ~y & z | x & y & ~z | x & y & z
    #return (x ^ 1) | (y ^ 1)  # x -> ~y
    return not(x) or not(y) or not(z)

#tt = truth_table_by_func(f_maj)
tt = truth_table_by_func(f)
#print(tt)

# СД "полином Жегалкина" -- это список списков из 3 элементов
#  такого вида: [-1, 0, 1],
#  каждый элемент списка кодирует слагаемое,
#  где -1 означает переменную с отрицанием, 0 - отсутствие переменной,
#  1 - переменная без отрицания

def xor_polynom_str(polynom):
    return '0' if polynom == [] else ' ⊕ '.join(map(term_str, polynom))


def term_str(term):
    assert(len(term) == 3)
    vars = ['x', 'y', 'z']
    s = []
    for i in range(3):
        if term[i] == 0:
            continue
        elif term[i] == -1:
            s.append('~' + vars[i])
        elif term[i] == 1:
            s.append(vars[i])
    if s == []:
        return '1'
    else:
        return '&'.join(s)

# тестирование
#term = [0, 0, 0]
#print(term_str(term))

# тестирование
#test_polynom = [[1, 0, 1], [1, 1, 0], [0, 0, 0]]
#print(xor_polynom_str(test_polynom))


# прибавляет к полиному терм такого вида: [1, 0, 1]
def add_simple_term_to_polynom(polynom, term):
    # привести терм к полиному без отрицаний
    for i in range(len(polynom)):
        if polynom[i] == term:
            del polynom[i]
            return
    polynom.append(term.copy())


# складывает два полинома Жегалкина (прибавляет второй к первому)
def add_polynoms(polynom1, polynom2):
    for polynom2_term in polynom2:
        add_simple_term_to_polynom(polynom1, polynom2_term)


# удаляет отрицания из терма
def convert_term_to_simple_polynom(term):
    # алгоритм: умножаем очередную переменную на многочлен
    #  также складываем многочлены
    #  индукция по переменным
    polynom = [[0, 0, 0]]
    for var in range(3):
        if term[var] == 1:
            for t in polynom:
                t[var] = 1
        elif term[var] == -1:
            polynom2 = [term.copy() for term in polynom]
            for t in polynom2:
                t[var] = 1
            add_polynoms(polynom, polynom2)
    return polynom


# прибавляет к полиному терм такого вида: [-1, 0, 1]
def add_term_to_polynom(polynom, term):
    # привести терм term к полиному polynom2 без отрицаний
    # "-1" = "0" + "1", то есть ~x = 1 + x
    polynom2 = convert_term_to_simple_polynom(term)
    #print('term = ', term)
    #print('polynom2 = ', polynom2)
    # прибавить polynom2 к polynom
    add_polynoms(polynom, polynom2)


# возвращает слагаемое СДНФ
def conj_term(vals):
    return [1 if d == 1 else -1  for d in vals]

# возвращает строку с полиномом Жегалкина по таблице истинности
def xor_polynom(tt):
    # находим СДНФ в описанном формате, то есть список списков такого вида: [-1, -1, 1]
    #  и затем прибавляем очередное слагаемое к результату
    polynom = []
    for key in tt:
        if tt[key]:
            term = conj_term(key)
            #print('term = ', term)
            add_term_to_polynom(polynom, term)
            #print('polynom = ', polynom)
    return polynom

def calc_xor_monom(monom, A, B, C):
    val = True
    if monom[0]:
        val = val and A
    if monom[1]:
        val = val and B
    if monom[2]:
        val = val and C  
    return val

def calc_xor_polynom(polynom, A, B, C):
    val = 0
    for monom in polynom:
        val ^= calc_xor_monom(monom, A, B, C)
    return val

def truth_table_of_xor_polynom(polynom):
    tt = {}
    for A in 0, 1:
        for B in 0, 1:
            for C in 0, 1:
                tt[A, B, C] = calc_xor_polynom(polynom, A, B, C)        
    return tt

def print_truth_table(tt):
    for key in tt:
        print(key, tt[key])

polynom = xor_polynom(tt)
#print(polynom)
print(xor_polynom_str(polynom))

tt_polynom = truth_table_of_xor_polynom(polynom)
#print(tt_polynom)
print("Таблица истинности для функции")
print_truth_table(tt)

print("Таблица истинности для полинома Жегалкина")
print_truth_table(tt_polynom)