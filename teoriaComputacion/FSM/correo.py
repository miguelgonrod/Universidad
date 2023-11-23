import sys

class EmailValidator:
    def __init__(self, transitions):
        self.transitions = transitions
        self.current_state = 'q1'
        self.accepting_state = 'q6'

    def process_input(self, input_str):
        for char in input_str:
            char_type = self.get_char_type(char)
            next_state = self.transitions[self.current_state][char_type]
            if next_state == 'q_error':
                return False
            self.current_state = next_state

        is_valid = self.current_state == self.accepting_state
        return is_valid

    def get_char_type(self, char):
        if char.isalpha():
            return 'letter'
        elif char == '@':
            return '@'
        elif char == '.':
            return '.'
        elif char.isnumeric():
            return 'number'
        elif char == '_':
            return '_'
        else:
            return 'other'


# Ejemplo de uso para verificar correos válidos
def main():
    transitions = {
        'q1': {'letter': 'q2', '@': 'q_error', '.': 'q_error', 'other': 'q_error'},
        'q2': {'letter': 'q2', '@': 'q3', '.': 'q2', '_': 'q2', 'number': 'q2','other': 'q_error'},
        'q3': {'letter': 'q4', '@': 'q_error', '.': 'q_error', 'number': 'q4', '_': 'q_error', 'other': 'q_error'},
        'q4': {'letter': 'q4', '@': 'q_error', '.': 'q5', '_': 'q_error', 'number': 'q4', 'other': 'q_error'},
        'q5': {'letter': 'q6', '@': 'q_error', '.': 'q_error', '_': 'q_error', 'number': 'q6', 'other': 'q_error'},
        'q6': {'letter': 'q6', '@': 'q_error', '.': 'q5', '_': 'number', 'number': 'q6', 'other': 'q_error'},
        'q_error': {'letter': 'q_error', '@': 'q_error', '.': 'q_error', 'other': 'q_error'}
    }
    validator = EmailValidator(transitions)

    is_valid = validator.process_input(sys.argv[1])
    print(f"{sys.argv[1]} - {'Válido' if is_valid else 'Inválido'}")
    validator.current_state="q1"


if __name__ == "__main__":
    main()