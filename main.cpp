#include "chord.h"
#include <vector>
#include <iostream>

void inserirAlunos(std::vector<ChordNode> &chordNodes, const std::vector<int> &allNodes, const std::vector<Aluno> &alunos)
{
    for (const Aluno &aluno : alunos)
    {
        int ra = aluno.getRa();
        int targetNodeID = -1;

        for (int nodeID : allNodes)
        {
            if (nodeID >= ra)
            {
                targetNodeID = nodeID;
                break;
            }
        }
        if (targetNodeID == -1)
        {
            targetNodeID = allNodes.front();
        }

        for (auto &node : chordNodes)
        {
            if (node.getNodeID() == targetNodeID)
            {
                node.insertKey(aluno);
                std::cout << "Aluno " << aluno.getNome() << " (RA: " << aluno.getRa() << ") inserido no noh " << targetNodeID << std::endl;
                break;
            }
        }
    }
}

void buscarAluno(std::vector<ChordNode> &chordNodes, const std::vector<int> &allNodes)
{
    std::cout << "\nDigite o RA do aluno que deseja buscar: ";
    int searchRA;
    std::cin >> searchRA;

    int nextNode = -1;
    for (int nodeID : allNodes)
    {
        if (nodeID >= searchRA)
        {
            nextNode = nodeID;
            break;
        }
    }
    if (nextNode == -1)
    {
        nextNode = allNodes.front();
    }

    for (auto &node : chordNodes)
    {
        if (node.getNodeID() == nextNode)
        {
            Aluno aluno;
            if (node.retrieveKey(searchRA, aluno))
            {
                std::cout << "Aluno encontrado: " << aluno.getNome() << " no noh " << nextNode << std::endl;
                return;
            }
        }
    }
    std::cout << "Aluno não encontrado!\n";
}

void removerAluno(std::vector<ChordNode> &chordNodes, const std::vector<int> &allNodes)
{
    std::cout << "\nDigite o RA do aluno que deseja remover: ";
    int removeRA;
    std::cin >> removeRA;

    int removeNodeID = -1;
    for (int nodeID : allNodes)
    {
        if (nodeID >= removeRA)
        {
            removeNodeID = nodeID;
            break;
        }
    }
    if (removeNodeID == -1)
    {
        removeNodeID = allNodes.front();
    }

    for (auto &node : chordNodes)
    {
        if (node.getNodeID() == removeNodeID)
        {
            node.deleteKey(removeRA);
            std::cout << "Aluno removido com sucesso.\n";
            return;
        }
    }
    std::cout << "Aluno não encontrado para remoção.\n";
}

void imprimirEstadoNos(const std::vector<ChordNode> &chordNodes)
{
    for (const auto &node : chordNodes)
    {
        node.printNode();
    }
}

int main()
{
    // std::vector<int> allNodes = {100, 500, 2000, 4000, 7000};

    // Declarando os novos nós chords DHT para caso de teste

    // Testes 1, 2, 3 e 4
    // std:: vector<int> testNodes = {98, 100, 102, 197, 201, 205};
    
    // Teste 5
    // std:: vector<int> testNodes = {449, 3499, 6199, 399, 10000};


    // /* Considere a situação nó 98, RA 99 e nó 100:
    //     Qual será o nó que a função irá decidir sabendo que o módulo da diferença 
    //     entre o RA, de valor 99, e os nós, 98 e 100, é a mesma?
    // */

    std::vector<ChordNode> chordNodes;
    for (int id : testNodes)
    {
        chordNodes.emplace_back(id);
    }
    for (auto &node : chordNodes)
    {
        node.updateFingerTable(testNodes);
    }

    // Testes 1 e 5
    // std::vector<Aluno> alunos = {
    //     Aluno(450, "Pedro"),
    //     Aluno(3500, "Maria"),
    //     Aluno(6200, "Lucas"),
    //     Aluno(400, "Joao")};

    // Testes 2, 3 e 4
    // std::vector<Aluno> alunos = {
    //     Aluno(99, "Pedro"),
    //     Aluno(101, "Maria"),
    //     Aluno(199, "Lucas"),
    //     Aluno(203, "Joao")};

    inserirAlunos(chordNodes, testNodes, alunos);
    buscarAluno(chordNodes, testNodes);
    removerAluno(chordNodes, testNodes);
    imprimirEstadoNos(chordNodes);

    return 0;
}
