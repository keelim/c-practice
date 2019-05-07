#include "AppController.h"

struct _AppController {
    char _expression[MAX_NUMBER_OF_TOKENS];
    Postfix *_postfix;
};

void AppController_run(AppController *_this) {
    Boolean expressionIsAvailable, noErrorIsInEvaluation;
    AppView_out_startingMessage();
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
    expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
    while (expressionIsAvailable) {
        Postfix_setExpression(_this->_postfix, _this->_expression);
        noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
        if (!noErrorIsInEvaluation) {
            AppView_out_errorInExpression();
        } else {
            AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));

        }
        expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
    }
    Postfix_delete(_this->_postfix);
    AppView_out_endingMessage();
}

