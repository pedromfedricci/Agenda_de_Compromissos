//
// Created by pedro on 10/03/18.
//

#ifndef NODE_H
#define NODE_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/**
 * Classe Node (Nó) é um container de objetos
 * genéricos 'T', enlaçado a outros dois Nodes
 * apontados por ponteiros internos. Essa classe participa
 * de uma lista duplamente encadeada, onde cada Nó indica
 * a posição de memória de um proximo Nó, e também a
 * posição de um anterior.
 * @tparam T template de objeto genérico 'T'
 */
template<class T> class Node {

public:
    Node();
    Node(T, Node<T>*,Node<T>*);
    explicit Node(T);
    T& getContent();
    void setContent(T);
    Node<T>* getNext() const;
    void setNext(Node<T>*);
    Node<T>* getPrevious() const;
    void setPrevious(Node<T>*);

private:
    T content;
    Node<T>* next;
    Node<T>* previous;
};

/**
 * Construtor padrão de Node
 * @tparam T T template de objeto genérico 'T'
 */
template<class T>
Node<T>::Node()
{
    Node::next = nullptr;
    Node::previous = nullptr;
}

/**
 * Construtor recebe um objeto genérico ('T')
 * 'newContent' e utiliza para inicializar
 * o atributo content ('T')
 * @tparam T T template de objeto genérico 'T'
 */
template<class T>
Node<T>::Node(T newContent)
{
    Node::next = nullptr;
    Node::previous = nullptr;
    setContent(newContent);
}

/**
 * Construtor recebe um conteúdo 'newContent' e dois
 * ponteiros 'nextNode' e 'previousNode' de objetos Node<T>
 * para inicializar o conteúdo e ponteiros internos
 * @tparam T template de objeto genérico 'T'
 * @param newContent novo conteúdo a ser carregado
 * @param nextNode ponteiro de Node<T> que indica o proximo Node<T>
 * @param previousNode ponteiro de Node<T> que indica o Node<T> anterior
 */
template<class T>
Node<T>::Node(T newContent, Node<T>* nextNode, Node<T>* previousNode)
{
    setContent(newContent);
    setNext(nextNode);
    setPrevious(previousNode);
}

/**
 * Get padrão do atributo 'content'
 * @tparam T template de objeto genérico 'T'
 * @return conteúdo 'content' encapsulado
 */
template<class T>
T& Node<T>::getContent() {
    return content;
}

/**
 * Set padrão do atributo 'content'
 * @tparam T template de objeto genérico 'T'
 * @param content conteúdo
 */
template<class T>
void Node<T>::setContent(T content) {
    Node::content = content;
}

/**
 * Retorna o endereço apontado por 'next',
 * a qual indica a posição de memória do proximo
 * Node<T>
 * @tparam T template de objeto genérico 'T'
 * @return endereço do proximo Node<T> apontado
 */
template<class T>
Node<T>* Node<T>::getNext() const {
    return Node::next;
}

/**
 * Set padrão do atributo 'next'
 * @tparam T template de objeto genérico 'T'
 * @param next sobrepõe o endereço apontado por 'next'
 */
template<class T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}

/**
 * Get padrão do atributo 'previous'
 * @tparam T template de objeto genérico 'T'
 * @return endereço no Node<T> anterior
 */
template<class T>
Node<T>* Node<T>::getPrevious() const {
    return Node::previous;
}

/**
 * Set padrão do atributo 'previous'
 * @tparam T template de objeto genérico 'T'
 * @param previous sobrepõe o endereço apontado por 'previous'
 */
template<class T>
void Node<T>::setPrevious(Node<T> *previous) {
    Node::previous = previous;
}

#endif //NODE_H
