#include "Streaming.hpp"
#include <iostream>
#include <string>

int main() {
  Streaming ss;
  std::string tipo;

  while (std::cin >> tipo) {
    if (tipo == "Filme") {
      std::string nome, genero;
      int ano, duracao;
      std::cin >> genero >> ano >> duracao;
      std::cin.ignore();
      std::getline(std::cin, nome);

      if (duracao >= 50) {
        Video *v = new Video(nome, ano, genero, tipo, duracao, 0, 0);
        ss.cadastrar_filme(v);
      }
    } else if (tipo == "Serie") {
      std::string nome, genero;
      int ano, n_temp, total_ep;
      std::cin >> genero >> ano >> n_temp >> total_ep;
      std::cin.ignore();
      std::getline(std::cin, nome);

      if (n_temp >= 2) {
        Video *v = new Video(nome, ano, genero, tipo, 0, n_temp, total_ep);
        ss.cadastrar_serie(v);
      }
    } else if (tipo == "Nota") {
      int id, nota;
      std::cin >> id >> nota;
      if (nota >= 0 && nota <= 10) {
        ss.avaliacao(id, nota);
      }
    }
  }

  ss.print_catalogo();

  return 0;
}