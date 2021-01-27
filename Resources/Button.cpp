#include "Button.h"

/* Constructors - Destructors */
Button::Button(float x, float y, float width, float height,
               sf::Font* font, std::string text, unsigned char_size,
               sf::Color text_idle_color, sf::Color text_hover_color , sf::Color text_active_color,
               sf::Color idle_color, sf::Color hover_color, sf::Color active_color)
{
    /* Idle state at the start */
    this->buttonState = BTN_IDLE;
    /* Setting shape values */
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idle_color);
    /* Setting font and text */
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_idle_color);
    this->text.setCharacterSize(char_size);
    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
            );
    /* Setting text colors */
    this->textIdleColor = text_idle_color;
    this->textHoverColor = text_hover_color;
    this->textActiveColor = text_active_color;
    /* Setting button colors */
    this->idleColor = idle_color;
    this->hoverColor = hover_color;
    this->activeColor = active_color;
}
Button::~Button() {

}
/* Accessors */

const bool Button::isPressed() const {
    return this->buttonState == BTN_ACTIVE;
}

/* Functions */
void Button::update(const sf::Vector2f mousePos) {
    /* Update the boolenas for hover and pressend */
    /* Idle */
    this->buttonState = BTN_IDLE;
    /* Hover */
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->buttonState = BTN_HOVER;
        /* Active */
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState = BTN_ACTIVE;
        }
    }
    /* Change color based on state */
    switch (this->buttonState) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
        break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            this->text.setFillColor(sf::Color::White);
            break;
    }
}

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}
