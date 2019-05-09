#pragma once
#include "AppController.h"

struct _AppController {
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;
};

<<<<<<< HEAD
AppController* AppController_new () { //AppController 생성
	AppController* _this;
	_this=NewObject (AppController); //dynamic allocation
	_this->_postfix=Postfix_new (MAX_NUMBER_OF_TOKENS);
	return _this;
}

void AppController_delete (AppController* _this) {
	Postfix_delete (_this->_postfix); //소멸
	free (_this);
}

void AppController_run (AppController* _this) {
	Boolean expressionIsAvailable;
	PostfixError evaluationError;
	AppView_out_startingMessage ();
	_this->_postfix=Postfix_new (MAX_NUMBER_OF_TOKENS);
	expressionIsAvailable=AppView_in_postfixExpression (_this->_expression);
	while (expressionIsAvailable) {
		Postfix_setExpression (_this->_postfix, _this->_expression);
		evaluationError=Postfix_evaluate (_this->_postfix);
		if (evaluationError == PostfixError_None) {
			AppView_out_evaluatedValue (Postfix_evaluatedValue (_this->_postfix));
		}
		else {
			AppView_out_postfixEvaluationErrorMessage (evaluationError);
=======
AppController* AppController_new () {  //AppController constructor
	AppController* _this=NewObject (AppController);
	_this->_postfix=Postfix_new (100);
	return _this;
}

void AppController_delete (AppController* _this) {  //AppController �Ҹ�
	Postfix_delete (_this->_postfix);
	free (_this); //free
}

void AppController_run(AppController *_this) {
    Boolean expressionIsAvailable;
    PostfixError evaluationError;
    AppView_out_startingMessage();
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
    expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
    while (expressionIsAvailable) {
        Postfix_setExpression(_this->_postfix, _this->_expression);
        evaluationError = Postfix_evaluate(_this->_postfix);
        if (evaluationError == PostfixError_None) {
            AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
        } else {
            AppView_out_postfixEvaluationErrorMessage(evaluationError);
>>>>>>> 0a8e1b0fec1b30a22f98a81d940362cc4ab26cc9

		}
		expressionIsAvailable=AppView_in_postfixExpression (_this->_expression);
	}
	Postfix_delete (_this->_postfix);
	AppView_out_endingMessage ();
}

