//
// Created by pedro on 14/03/18.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList;
template<class T>
ostream& operator<<(ostream&, const DoublyLinkedList<T> &);

/**
 * Classe representa uma lista dinâmica duplamente
 * encadeada, onde os conteúdos (objetos genéricos 'T')
 * são encapsulados por Nós ('Node'). Nós são alocados
 * dinâmicamente pela lista, e cada Nó além de carregar o
 * conteúdo, aponta para um Nó anterior e para um proximo Nó.
 * A lista mantém o endereço do primeiro e último Nó, e
 * apartir desses pode alcançar qualquer outro.
 * Os conteúdos inseridos são orientados por ordenação crescente,
 * dessa forma, objetos devem sobrecarregar os operadores == !=
 * <= < >= > para serem inseridos, buscados e removidos.
 * @tparam T template de objeto genérico 'T'
 */
template<class T>
class DoublyLinkedList {

public:
    long getSize() const;
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertInOrder(T &);
    void printList(const string&, const string&);
    Node<T>* linearSearch(T &);
    bool removeOne(T &);
    bool iterate(T &, long);

    DoublyLinkedList<T>&operator=(const DoublyLinkedList<T>&);
    friend ostream& operator<< <T>(ostream &os, const DoublyLinkedList<T> &list);

private:
    long size;
    Node<T>* tail;
    Node<T>* header;
    void setSize(long);
};

/**
 * Contrutor padrão de objetos 'DoublyLinkedList'
 * @tparam T template de objeto genérico 'T'
 */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    DoublyLinkedList::size = 0;
    DoublyLinkedList::header = nullptr;
    DoublyLinkedList::tail = nullptr;
}

/**
 * Get padrão do atributo 'size'
 * @tparam T template de objeto genérico 'T'
 * @return
 */
template<class T>
long DoublyLinkedList<T>::getSize() const {
    return DoublyLinkedList::size;
}

/**
 * Set padrão do atributo 'size'
 * @tparam T template de objeto genérico 'T'
 * @param size sobrepõe o atributo 'size'
 */
template<class T>
void DoublyLinkedList<T>::setSize(long size) {
    DoublyLinkedList::size = size;
}

/**
 * Aloca dinâmicamente um novo Node<T> para carregar o novo
 * conteúdo da lista. A inserção é ordenada de forma
 * crescente.
 * @tparam T template de objeto genérico 'T'
 * @param newContent novo conteúdo
 */
template<class T>
void DoublyLinkedList<T>::insertInOrder(T &newContent)
{
    auto *node = new Node<T>(newContent);

    Node<T> *current = header;
    Node<T> *previous = nullptr;

    while (current && newContent > current->getContent())
    {
        previous = current;
        current = current->getNext();
    }

    if (previous) {
        previous->setNext(node);
        node->setPrevious(previous);
    }
    else header = node;

    if (current)
        current->setPrevious(node);
    else tail = node;

    node->setNext(current);
    DoublyLinkedList::size++;
}

/**
 * Imprime no console os conteúdos da lista em
 * ordem crescente apontada pelos ponteiros
 * @tparam T template de objeto genérico 'T'
 * @param txt texto inicial da impressão
 * @param format formatação entre as saídas
 */
template<class T>
void DoublyLinkedList<T>::printList(const string &txt,const string &format)
{
    Node<T> *current = header;

    cout << txt;
    while(current)
    {
        cout << current->getContent() << format;
        current = current->getNext();
    }
}

/**
 * Destrutor desaloca os Node<T> da lista
 * @tparam T template de objeto genérico 'T'
 */
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T> *current = header;
    Node<T> *previous = nullptr;

    while(current)
    {
        previous = current;
        current = current->getNext();
        delete(previous);
        size--;
    }
    //cout << "\n" << "Nodes nao desalocados: " << size << endl;
}

/**
 * Retorna o endereço do Node<T> que carrega o
 * conteúdo procurado
 * @tparam T template de objeto genérico 'T'
 * @param matchContent conteúdo procurado
 * @return
 */
template<class T>
Node<T>* DoublyLinkedList<T>::linearSearch(T &matchContent)
{
    Node<T> *current = header;

    while(current)
    {
        if (matchContent == current->getContent())
            return current;

        current = current->getNext();
    }

    return nullptr;
}

/**
 * Remove o Node<T> que carrega o conteúdo indicado
 * pelo 'matchContent', se esse existir, retornando True,
 * caso contrario, nenhum Node<T> é removido, é retornado
 * um booleano False
 * @tparam T template de objeto genérico 'T'
 * @return booleano que indica o sucesso da operação
 */
template<class T>
bool DoublyLinkedList<T>::removeOne(T &matchContent)
{
    Node<T>* nodeMatch = linearSearch(matchContent);

    if(!nodeMatch) return false;

    if (nodeMatch == tail)
        tail = nodeMatch->getPrevious();

    if (nodeMatch->getPrevious())
        nodeMatch->getPrevious()->setNext(nodeMatch->getNext());

    else header = nodeMatch->getNext();

    delete(nodeMatch);
    size--;

    return true;
}

/**
 * Sobrecarga aloca uma nova série de Node<T>
 * para uma lista, carregando o conteúdo de outra lista
 * @tparam T template de objeto genérico 'T'
 * @param list lista da classe 'DoublyLinkedList'
 * @return objeto 'DoublyLinkedList' resultado da operação
 */
template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list)
{
    if (!list.header)
    {
        DoublyLinkedList::header = nullptr;
        DoublyLinkedList::tail = nullptr;
    }
    else
    {
        Node<T> *current = list.header;
        while (current)
        {
            DoublyLinkedList::insertInOrder(current->getContent());
            current = current->getNext();
        }
    }
    return *this;
}

/**
 * Sobrecarga define como criar um 'ostream&'
 * apartir de uma objeto'DoublyLinkedList'
 * @tparam T template de objeto genérico 'T'
 * @param os ostream&
 * @param list lista da classe 'DoublyLinkedList'
 * @return ostream&
 */
template<class T>
ostream& operator<<(ostream &os, const DoublyLinkedList<T> &list)
{
    Node<T> *current = list.header;

    while(current)
    {
        os << current->getContent() << endl;
        current = current->getNext();
    }

    return os;
}

/**
 *
 * @tparam T
 * @param outContent
 * @param index
 * @return
 */
template<class T>
bool DoublyLinkedList<T>::iterate(T & outContent, long qnt)
{
    if (qnt <= 0 || qnt > getSize() || !header)
        return false;

    Node<T> *current = header;

    while(--qnt)
        current = current->getNext();

    outContent = current->getContent();

    return true;
}

#endif //DOUBLYLINKEDLIST_H
