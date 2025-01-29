#include "Form.hpp"

Form::Form(int required_grade_to_sign, int required_grade_to_execute)
	: _required_grade_to_sign(required_grade_to_sign), _required_grade_to_execute(required_grade_to_execute) {}

Form::Form(const Form& form)
	: _required_grade_to_sign(form._required_grade_to_sign), _required_grade_to_execute(form._required_grade_to_execute) {}

Form::~Form() {}


