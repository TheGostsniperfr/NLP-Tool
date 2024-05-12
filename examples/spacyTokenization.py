import spacy
nlp = spacy.load('en_core_web_sm')

sentence = "Apple is looking at buying U.K. startup for $1 billion Autonomous cars shift insurance liability toward manufacturers San Francisco considers banning sidewalk delivery robots London is a big city in the United Kingdom. Where are you? Who is the president of France? What is the capital of the United States? When was Barack Obama born?"
doc = nlp(sentence)

for token in doc:
    print(token.text, token.pos_)
