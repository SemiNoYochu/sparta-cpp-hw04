#include <iostream>
#include <string>
#include <vector>

#include "PotionManager.h"

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
//void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
//{
//    recipes.push_back(PotionRecipe(name, ingredients));
//    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
//}

// 레시피를 받아 레시피 벡터에 추가
void AlchemyWorkshop::addRecipe(const PotionRecipe& _pRecipes)
{
    recipes.push_back(_pRecipes);
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const
{
    // 등록된 레시피가 없는 경우
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    // 등록된 전체 레시피 출력
    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            std::cout << recipes[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].ingredients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}
