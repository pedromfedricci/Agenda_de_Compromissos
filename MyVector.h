//
// Created by pedro on 17/03/18.
//

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

/**
 * MyVector é uma lista sequêncial dinâmica,
 * insere seguindo uma ordenação crescente,
 * a partir de buscas binárias para encontrar
 * a posição coerente de inserção. Buscas e
 * remoções também são processadas por busca binária.
 * A lógica de comparação é determinada por operadores
 * lógicos (== != > >= < <=), dessa forma, objetos devem
 * sobrecarregar esses operadores para serem inseridos.
 * @tparam T template de objeto genérico 'T'
 */
template<class T> class MyVector {

public:
    explicit MyVector(long);
    MyVector();
    ~MyVector();
    long getSize() const;
    T & contentAt(long) const;
    long searchIndex(T &);
    bool hasContent(T &);
    bool insertInOrder(T &);
    bool removeOne(T &);
    void printList(const string &, const string &);

private:
    void setSize(long);
    void setAllocated(long);
    void addOneToSize();
    void subtractOneFromSize();
    void reallocate(long);
    long getAllocated() const;
    bool hasReachedLimit();

    long size;
    long allocated;
    T *array;
};


/**
 * Construtor aloca a quantidade de posições definidas pelo parâmetro
 * 'allocate', size é mantido em 1 pois a primeira posição de 'array'
 * (array[0]) não é ultilizada para manter objetos úteis.
 * @tparam T template de objeto genérico 'T'
 * @param allocate quantidade a ser alocada
 */
template<class T>
MyVector<T>::MyVector(long allocate)
{
    setAllocated(allocate);
    size = 1;
    array = new T[getAllocated()];
}

/**
 * Contrutor aloca a quantidade pré-definida de 10 posições, sendo
 * dessas apenas 9 aptas a carregarem objetos úteis, a primeira posição
 *  de 'array' (array[0]) não pode ser ultilizada. Size é iniciado em
 *  1 por conta dessa caracteristica.
 * @tparam T template de objeto genérico 'T'
 */
template<class T>
MyVector<T>::MyVector()
{
    allocated = 10;
    size = 1;
    array = new T[allocated];
}

/**
 * Destrutor padrão desaloca objetos dinâmicos do vetor,
 * com uso de 'delete[]', assim os destrutor dos objetos
 * alocados é chamado.
 */
template<class T>
MyVector<T>::~MyVector() {
    delete[] array;
}

/**
 * Get padrão do atributo 'allocated'
 * @tparam T template de objeto genérico 'T'
 * @return allocated quantidade de posições alocadas
 */
template<class T>
long MyVector<T>::getAllocated() const {
    return allocated;
}

/**
 * Set define nova quantidade de alocação do vetor,
 * desde que a seja maior do que 1, caso contrario
 * a alocação é definida em 2
 * @tparam T template de objeto genérico 'T'
 * @param allocate nova quantiade de alocação
 */
template<class T>
void MyVector<T>::setAllocated(long allocate)
{
    if (allocate <= 1)
        this->allocated = 2;

    else this->allocated = allocate;
}

/**
 * Set define uma nova quantidade de posições ocupadas
 * no vetor, desde que seja maior do que zero e menor
 * que a quantidade total de posições do vetor.
 * @tparam T template de objeto genérico 'T'
 * @param size nova quantidade de posições OCUPADAS
 */
template <class T>
void MyVector<T>::setSize(long size)
{
    if (size < 0)
        this->size = 0;

    else if (size > getAllocated())
        this->size = getAllocated();

    else this->size = size;
}

/**
 * Get padrão do atributo 'size'
 * @tparam T template de objeto genérico 'T'
 * @return quantidade de posições ocupadas
 */
template <class T>
long MyVector<T>::getSize() const {
    return MyVector::size;
}

/**
 * Adiciona 1 ao atributo 'size'
 * @tparam T template de objeto genérico 'T'
 */
template <class T>
void MyVector<T>::addOneToSize() {
    setSize(getSize() + 1);
}

/**
 * Subtrai 1 do atributo 'size'
 * @tparam T template de objeto genérico 'T'
 */
template <class T>
void MyVector<T>::subtractOneFromSize() {
    setSize(getSize() - 1);
}

/**
 * Retorna o conteúdo no vetor na posição indicada,
 * se o valor não coincidir com los limites do vetor,
 * o conteúdo 'default' gravado no índice 0 é retornado
 * @tparam T template de objeto genérico 'T'
 * @return conteúdo presente na posiçao indicada
 */
template<class T>
T & MyVector<T>::contentAt(long value) const
{
    if (value > 0 && value < getSize())
        return array[value];

    else return array[0];
}

/**
 * Busca no vetor um certo conteúdo, se for encontrado,
 * a função retorna o índice (positivo e diferente de zero)
 * na qual o conteúdo se encontra. Se o conteúdo de busca não for
 * encontrado no vetor, um valor negativo (que em módulo representa
 * a posição a qual o conteúdo seria inserido seguindo a lógica
 * de ordenação) será retornado.
 * @tparam T template de objeto genérico 'T'
 * @param searchValue conteúdo a ser procurado
 * @return índice do conteúdo procurado
 */
template<class T>
long MyVector<T>::searchIndex(T &searchValue)
{
    long upperBound = getSize() - 1;
    long lowerBound = 1;
    long mid;

    while (lowerBound <= upperBound)
    {
        mid = lowerBound + (upperBound - lowerBound) / 2;

        if (searchValue == array[mid])
            return mid;

        else if (searchValue > array[mid])
            lowerBound = mid + 1;

        else upperBound = mid - 1;
    }

    return -1 * lowerBound;
}

/**
 * Método busca determinado conteúdo no vetor,
 * se for encontrado, é retornado um booleano True,
 * se não for encontrado, retorna False
 * @tparam T template de objeto genérico 'T'
 * @param search conteúdo procurado
 * @return booleano que indica a existência do conteúdo
 */
template<class T>
bool MyVector<T>::hasContent(T &search) {
    return searchIndex(search) >= 1;
}

/**
 * Método indica se o fim de posições não ocupadas no
 * vetor foi alcançado, retornando True ou False
 * @tparam T template de objeto genérico 'T'
 * @return booleano que indica se o fim do espaço alocado
 * foi alcançado
 */
template<class T>
bool MyVector<T>::hasReachedLimit() {
    return getSize() >= getAllocated();
}

/**
 * Método realoca um novo (e maior) espaço de memória
 * para o vetor seguindo o valor indicado pelo parâmetro
 * @tparam T template de objeto genérico 'T'
 * @param newAllocation novo tamanho de alocação
 */
template<class T>
void MyVector<T>::reallocate(long allocationLength)
{
    if (allocationLength <= getSize())
        return;

    auto *newAllocation = new T[allocationLength];

    copy(array, this->array + getSize(), newAllocation);

    setAllocated(allocationLength);

    delete[] array;
    array = newAllocation;
}

/**
 * Insere um novo conteúdo no vetor, retornando
 * um booleano que indica o sucesso na operação.
 * Se não houver mais espaço para a nova inserção,
 * o vetor será realocado dinâmicamente para um novo
 * e maior espaço
 * @tparam T template de objeto genérico 'T'
 * @param newContent novo conteúdo a ser inserido
 * @return booleano que indica o sucesso da inserção
 */
template<class T>
bool MyVector<T>::insertInOrder(T &newContent)
{
    if (hasReachedLimit())
        reallocate(2 * getAllocated());

    long pos = searchIndex(newContent);

    if (pos >= 0)
    {
        cout << "Conteudo ja inserido!: "
             << newContent << endl;
        return false;
    }

    pos = abs(pos);

    for (long j = getSize() - 1; j >= pos; j--)
        array[j + 1] = array[j];

    array[pos] = newContent;

    addOneToSize();
    return true;
}

/**
 * Remove o conteúdo indicado pela entrada no
 * parâmetro, se o conteúdo existir no vetor,
 * ele será retirado e o método vai retornar um
 * booleano True, caso contrário, nenhum valor será
 * retirado e será retornado False
 * @tparam T template de objeto genérico 'T'
 * @param searchContent conteúdo a ser removido
 * @return booleano que indica o sucesso na operação
 */
template<class T>
bool MyVector<T>::removeOne(T & searchContent)
{
    long index = searchIndex(searchContent);

    if (index <= 0)
        return false;

    for (long j=index; j < getSize() - 1;j++)
        array[j] = array[j+1];

    subtractOneFromSize();

    if (getSize() <= getAllocated() / 2 && getSize() + 1 >= 10)
        reallocate(getSize() + 1);

    return true;
}

/**
 * Imprime no console os conteúdos do vetor em
 * ordem crescente de índice
 * @tparam T template de objeto genérico 'T'
 * @param text texto inicial da impressão
 * @param format formatação entre as saídas
 */
template<class T>
void MyVector<T>::printList(const string & text, const string & format)
{
    cout << text;
    for (long i=1; i < getSize(); i++)
        cout << array[i] << format;
    cout << "Numero de elementos inseridos: " << getSize() - 1
         << format << endl;
}

#endif //MYVECTOR_H
