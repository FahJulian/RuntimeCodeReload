FILE_NAME = 'macros.txt'
MAX_ARGUMENTS_COUNT = 50

def write_function_macros(file, max_arguments_count):
    for n in range(max_arguments_count + 1):
        macro = f'#define SN_RCR_FUNCTION_{n}_ARGS(returnType, name, '

        for m in range(n):
            if (m - 3) % 5 == 0:
                macro += '\\\n    '
            macro += f'arg{m}Type, arg{m}Name, '

        macro += '...) \\\n        '

        macro += 'SN_RCR_FUNCTION(returnType, name, ('
        for m in range(n):
            macro += f'arg{m}Type arg{m}Name'
            if m != (n - 1): macro += ', '
            if m % 5 == 4 and m != n - 1:
                macro += '\\\n        '
        
        macro += '), '

        currentTokensInLine = (n % 5) * 2

        for m in range(n):
            if (currentTokensInLine + 2 * m) % 10 == 0 and m != n - 1:
                macro += '\\\n        '   
            macro += f'arg{m}Type'
            if m != (n - 1): macro += ' SN_NEXT_TYPE '    


        currentTokensInLine = (currentTokensInLine + 2 * (n - 1)) % 10 + 1
        if (currentTokensInLine == 1):
            currentTokensInLine = 11

        currentTokensInLine -= currentTokensInLine % 2

        macro += f', ('
        if currentTokensInLine % 10 == 0: macro += ' '

        for m in range(n):
            if (currentTokensInLine + 2 * m) % 10 == 0:
                macro += '\\\n        '   
            macro += f'std::forward<arg{m}Type>(arg{m}Name)'
            if m != n - 1: macro += ', '

        macro += '), __VA_ARGS__)'

        file.write(macro + '\n\n')

def write_method_macros(file, max_arguments_count):
    for n in range(max_arguments_count + 1):
        macro = f'#define SN_RCR_MEMBER_FUNCTION_{n}_ARGS(returnType, name, '

        for m in range(n):
            if (m - 3) % 5 == 0:
                macro += '\\\n    '
            macro += f'arg{m}Type, arg{m}Name, '

        macro += '...) \\\n        '

        macro += 'SN_RCR_MEMBER_FUNCTION(returnType, name, ('
        for m in range(n):
            macro += f'arg{m}Type arg{m}Name'
            if m != (n - 1): macro += ', '
            if m % 5 == 4 and m != n - 1:
                macro += '\\\n        '
        
        macro += '), '

        currentTokensInLine = (n % 5) * 2

        for m in range(n):
            if (currentTokensInLine + 2 * m) % 10 == 0 and m != n - 1:
                macro += '\\\n        '   
            macro += f'arg{m}Type'
            if m != (n - 1): macro += ' SN_NEXT_TYPE '    


        currentTokensInLine = (currentTokensInLine + 2 * (n - 1)) % 10 + 1
        if (currentTokensInLine == 1):
            currentTokensInLine = 11

        currentTokensInLine -= currentTokensInLine % 2

        macro += f', ('
        if currentTokensInLine % 10 == 0: macro += ' '

        for m in range(n):
            if (currentTokensInLine + 2 * m) % 10 == 0:
                macro += '\\\n        '   
            macro += f'std::forward<arg{m}Type>(arg{m}Name)'
            if m != n - 1: macro += ', '

        macro += '), __VA_ARGS__)'

        file.write(macro + '\n\n')

def main():
    with open(FILE_NAME, mode='w') as file:
        write_function_macros(file, MAX_ARGUMENTS_COUNT)
        write_method_macros(file, MAX_ARGUMENTS_COUNT)
    
if __name__ == '__main__':
    main()
