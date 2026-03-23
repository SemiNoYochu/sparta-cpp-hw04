#pragma once

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
public:
    std::string potionName;
    std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경

public:
    PotionRecipe& operator *()
    {
        return *this;
    }

public:
    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
        : potionName(name)
        , ingredients(ingredients)
    {
    }
};

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    // void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 레시피를 받아 레시피 벡터에 추가
    void addRecipe(const PotionRecipe& _pRecipes);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;
};