#include <iostream>
#include <vector>
#include <string>

#include "PotionManager.h"

int main() {
    // AlchemyWorkshop 스택 영역에 인스턴스화
    AlchemyWorkshop myWorkshop;

    while (true)
    {
        // 연금술 공방 관리 시스템 UI 제공
        std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 레시피 검색" << std::endl;
        std::cout << "3. 모든 레시피 출력" << std::endl;
        std::cout << "4. 종료" << std::endl;
        std::cout << "선택: ";

        // 연금술 공방 관리 시스템 번호 변수 생성 및 입력
        int choice;
        std::cin >> choice;

        // 입력된 값이 올바른 자료형(int)가 아닌 경우의 예외 처리
        if (std::cin.fail())
        {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // 1. 레시피 추가
        if (choice == 1)
        {
            // 물약 이름을 입력받기 위한 로직
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true)
            {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝")
                {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty())
            {
                //myWorkshop.addRecipe(name, ingredients_input);
                myWorkshop.addRecipe(PotionRecipe(name, ingredients_input));
            }
            else
            {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2)
        {
            int choice;

            while (true)
            {
                std::cout << "검색할 방법을 선택하세요." << std::endl;
                std::cout << "1. 포션 이름을 통한 검색" << std::endl;
                std::cout << "2. 포션 재료를 통한 검색" << std::endl;

                std::cin >> choice;

                // 입력된 값이 올바른 자료형(int)가 아닌 경우의 예외 처리
                if (std::cin.fail())
                {
                    std::cout << "잘못된 입력입니다." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    continue;
                }
                else
                    break;
            }

            if (1 == choice)
            {
                std::cout << "물약을 검색하기 위해 필요한 이름을 입력하세요." << std::endl;

                // 물약 이름을 입력받기 위한 로직
                std::string name;
                std::cout << "이름 입력 : ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, name);

                myWorkshop.findRecipeByName(name);
            }
            else if(2 == choice)
            {
                std::cin.ignore(10000, '\n');

                // 여러 재료를 입력받기 위한 로직
                std::vector<std::string> ingredients_input;
                std::string ingredient;
                std::cout << "물약을 검색하기 위해 필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

                while (true)
                {
                    std::cout << "재료 입력: ";
                    std::getline(std::cin, ingredient);

                    // 사용자가 '끝'을 입력하면 재료 입력 종료
                    if (ingredient == "끝")
                    {
                        break;
                    }
                    ingredients_input.push_back(ingredient);
                }

                myWorkshop.findRecipeByIngredients(ingredients_input);
            }
            else
            {
                std::cout << ">> 검색 방법이 잘못 입력되어 레시피 검색을 취소합니다." << std::endl;
            }
        }
        // 3. 모든 레시피 출력
        else if (choice == 3)
        {
            myWorkshop.displayAllRecipes();

        }
        // 4. 종료
        else if (choice == 4)
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;

            break;

        }
        // 제공하는 목록 번호 이외의 번호인 경우의 예외 처리
        else
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}