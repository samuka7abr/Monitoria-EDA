/// Declare uma variável `int x = 42` e um ponteiro `p`.  
/// Atribua a `p` o endereço de `x` e imprima:
/// - O valor de `x`
/// - O endereço de `x` com `&x`
/// - O valor armazenado em `p`
/// - O conteúdo de `p` com `*p`/// 


#include <stdio.h>


int main(){

    int x = 42; 
    int* p; 
    
    p = &x; 

    /// O valor de 'x'
    printf("Valor de X: %d\n", x); 

    /// - O endereço de `x` com `&x`
    printf("Endereço de X: %p\n", &x); 

    /// - O valor armazenado em `p`
    printf("Valor armazenado em p: %p\n", p); 

    /// - O conteúdo de `p` com `*p`/// 
    printf("Conteúdo de p: %d", *p);
















}







