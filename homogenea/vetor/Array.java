public class Array {
  public static void main(String[] args) {

    /*
     * Arrays, também chamados de vetores, apresenta uma estrutura 
     * de armazenamento linear na memória, ou seja,
     * os elementos estão dispostos um ao lado do outro
     * 
     * Ex: 
     * Em um array que possua os valores 3,5,7 apresentaria um valor ao lado do outro na memória da seguinte forma:
     * _____________
     * | 3 | 5 | 7 | 
     * ¯¯¯¯¯¯¯¯¯¯¯¯¯
     * 
     * Tempo de execução para operações comuns em arrays:
     * Leitura:  O(1)
     * Inserção: O(n)
    */
    int[] array = {1,2,3,4,5,6,7,8,9};

    for (int i : array) {
      System.out.println(i);
    }
  }
}