#include "util.h"
#include "constants.h"

InfoManager::InfoManager(sf::Vector2i position, std::string title)
    : window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), title),
      title(title),
      position(position),
      maxWidth(0),
      prevMaxWidth(0) {
    window.setPosition(position);

    if (!font.loadFromFile("C:\\SFML\\arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
}

int InfoManager::AddInfo(std::string label) {
    sf::Text newLabel;
    newLabel.setFont(font);
    newLabel.setCharacterSize(TEXT_FONT_SIZE);
    newLabel.setString(label);

    if (labels.empty()) {
        newLabel.setPosition(TEXT_MARGIN, TEXT_MARGIN);
    } else {
        sf::Vector2f lastLabelPosition = labels.back().getPosition();
        newLabel.setPosition(lastLabelPosition.x, lastLabelPosition.y + TEXT_FONT_SIZE + TEXT_MARGIN);
    }

    labels.push_back(newLabel);
    return labels.size() - 1;
}

void InfoManager::UpdateSize(int width, int height) {
    window.close();
    window.create(sf::VideoMode(width, height), title);
    window.setPosition(position);
}

void InfoManager::UpdateInfo(int idx, std::string label) {
    labels[idx].setString(label);

    int newWidth = static_cast<int>(labels[idx].getLocalBounds().width);
    if (newWidth > maxWidth) {
        maxWidth = newWidth;
        std::pair<int, int> dimensions = CalculateSize();
        UpdateSize(dimensions.first, dimensions.second);
    }
}

void InfoManager::DrawInfo() {
    window.clear();
    for (const auto& label : labels) {
        window.draw(label);
    }
    window.display();
}

std::pair<int, int> InfoManager::CalculateSize() {
    int width = maxWidth + 2 * TEXT_MARGIN;
    int height = labels.size() * (TEXT_MARGIN + TEXT_FONT_SIZE) + TEXT_MARGIN;

    return std::make_pair(width, height);
}