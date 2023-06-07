#include "Video.hpp"
#include <iostream>

Video::Video(std::string nome, int ano, std::string genero, std::string subtipo,
             int filme_duracao, int n_temp, int total_ep)
    : nome(nome), ano(ano), genero(genero), subtipo(subtipo),
      filme_duracao(filme_duracao), n_temp(n_temp), total_ep(total_ep) {}

float Video::get_media_avaliacao() const {
  if (avaliacoes.empty()) {
    return 0;
  }
  float soma = 0;
  for (const auto &nota : avaliacoes) {
    soma += nota;
  }
  return soma / avaliacoes.size();
}

void Video::avaliar(int nota) {
  if (nota >= 0 && nota <= 10) {
    avaliacoes.push_back(nota);
  }
}

void Video::print_info(int id) const {
  std::cout << subtipo << " " << id << ": ";
  std::cout << nome << " (" << ano << "), ";
  std::cout << genero;
  if (subtipo == "Filme") {
    std::cout << ", " << filme_duracao << " min, ";
  } else if (subtipo == "Serie") {
    std::cout << ", " << n_temp << " temporadas, " << total_ep
              << " episodios, ";
  }
  std::cout << "nota: " << get_media_avaliacao() << std::endl;
}