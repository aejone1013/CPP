/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:36:42 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 17:06:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4];  // 4개의 템플릿 저장
    
    void clearTemplates();

public:
    // Orthodox Canonical Form
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    // IMateriaSource 인터페이스 구현
    void learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const & type);

    // 유틸리티 함수
    void printTemplates() const;
};

#endif
