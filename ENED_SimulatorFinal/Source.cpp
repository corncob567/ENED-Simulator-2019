#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <SFML/Audio/Music.hpp>

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
std::set<int> prev_questions; // Holds questions already encountered

sf::RectangleShape drawNextButton(sf::Font font, sf::RenderWindow& window) {
	sf::Vector2f nbuttonSize = { 150,100 };
	sf::RectangleShape nextButton(nbuttonSize);
	nextButton.setPosition(SCREEN_WIDTH - 180, SCREEN_HEIGHT - 130);
	nextButton.setFillColor(sf::Color::Color(100, 100, 100, 255));

	sf::Text nextText("Next >", font, 72);
	nextText.setFillColor(sf::Color::White);
	nextText.setPosition(SCREEN_WIDTH - 170, SCREEN_HEIGHT - 130);

	window.draw(nextButton);
	window.draw(nextText);
	return nextButton;
}
void currentDate(int date, sf::Font font,sf::RenderWindow& window);
void drawProgress(int projectProgress, sf::Font font, sf::RenderWindow& window);


void QA(std::string& q, std::string& a1, std::string& a2, std::string& a3, std::string& a4) {
	
	std::vector<std::string> questions = { "If you are bald, what hair color do they put on your driver's license?", "When does it start being partly cloudy and stop being partly sunny?", "A student walks up to you and says 'ENED Bad'. This is considered: ", "What does RAT stand for?", "What does CFU stand for?", "Stealing an entire curriculum is considered: ", "What is the airspeed velocity of an unladen swallow?", "What is the syntax for declaring a variable in VBA?", "Does Chocolate start with a C or a K?", "A bear falls into a well. The depth of the well is 19.617 meters\nand it takes the bear 2 seconds to reach the bottom.\nWhat is the color of the bear?", "Is a tomato a fruit or a vegetable?", "How do you pronounce the name of this course?", "How do you pronounce 'GIF'?", "What do you can?", "What index do arrays start at in MATLAB?", "What is the purpose of the semicolon in MATLAB?", "What is the name of the male voice in the preclass modules?", "Why do so many potato chips have ridges now?", "What is the name of the female voice in the preclass modules?", "How much power does Emperor Palpatine possess?", "What's 9 + 10?", "How much wood could a woodchuck chuck if a woodchuck could chuck wood?", "How many centimeters are in an inch?", "Android or iPhone?", "What is the name of Drake's younger sister?", "Rumor has it that there is a RAT coming up next week. Is it unethical to spread the word?", "What is the 95% confidence interval that you will pass this class?", "What is your favorite color?", "What is your quest?", "Where is Kony?", "When did ENED become great?", "Who is Bolby?", "Where in the world is Carmen Sandiego?", "Which way is up?", "What is the file extension for a MATLAB program?", "Which loop will always run at least once?", "What button in the MATLAB is best to use to find documentation about unknown functions?", "How much does the student version of MATLAB cost?", "What sensor does Lego Mindstorms use to detect objects in front of you?", "What sensor does Lego Mindstorms use to follow a black line?", "How many 2-stud pegs are included in your Lego Mindstorms kit?", "Who dat boy?", "What is a Macro in VBA?", "Your spouse is dating other people behind your back. This is: ", "Complete the analogy: Coding is to Lego Mindstorms as Swimming is to:" };
	std::vector<std::string> answer1r = { "Kwuimy", "At about 2pm", "Cheating, but not unethical", "Readiness Assessment Test", "Check for Understanding", "Neither cheating not unethical", "African or Europeon Swallow?", "Dim x As Integer", "C", "Brown", "Vegetable", "Engineering Education", "Gif", "Peaches", "1", "Suppresses output", "James", "They are solely to annoy you", "Julie", "Unlimited Power", "21", "2 tons", "2.54", "No phones allowed", "Meghan", "Ethical but cheating.", "1%", "Blue", "To pass ENED", "The world may never know", "2019", "Clap clap clap, slap slap slap", "San Diego", "North", ".m", "Do While", "The Help Button", "$100 freaking dollars", "Ultrasonic Sensor", "Color Sensor", "198", "Who him is?", "A small custom application", "ChEaTiNg", "Lava" };
	std::vector<std::string> answer2 = { "White", "Anytime after 3am", "Just cheating", "Rats Are Tasty", "Canned Foods United", "UnEtHiCaL", "Like...7?", "int x;", "K", "White", "Fruit", "E-ned", "Gif", "Pickles", "0", "Breaks your loops", "Byron", "They're good for dipping", "A-A-ron", "25 J", "19", "A little bit", "100", "Android", "Miranda", "No, but it is cheating.", "5%", "Green", "To beat the snot out of anyone who trys me", "Somewhere in Uganda", "2078", "The comedic relief for the greatest show known to mankind", "New Zealand", "Up", ".mat", "While", "The Run Button", "$50", "Infrared Sensor", "Infrared Sensor", "209", "Rick", "A type of pasta", "Very ethical", "Water" };
	std::vector<std::string> answer3 = { "N/A", "Never", "UnEtHiCaL", "Rabies And Tuberculosis", "Corporate Finance Unit", "Cheating", "89 mph", "Open the Numberic Palette and select Numeric Control", "C", "Black", "Grain", "E-N-E-D", "Gif", "Huh?", "-1", "Acts as a placeholder for array values", "Mitchell", "They hurt the roof of your mouth", "Jasmine", "1.21 GW", "-1", "None", "4.35", "iPhone", "Meegan", "Just cheating.", "100%", "Red", "To find the Holy Grail", "The Netherlands", "It always has been", "Bolby is not a person, it is a German sausage", "Argentina", "Forward", ".matlab", "For", "The Bruh Button", "Well it should be free.", "Touch Sensor", "Ultrasonic Sensor", "78", "Young Sheldon", "A Pro Wrestler", "Unethical, but not cheating.", "Ocean" };
	std::vector<std::string> answer4 = { "Brown", "The time is ever-changing", "Neither cheating nor unethical", "Rude and Thirsty", "Colored Fruit Union", "Cheating and Unethical", "88 mph", "x = 3", "K", "Invalid Question", "Berry", "EN-ed", "Gif", "Yes", "Arrays don't exist in MATLAB", "It has no use", "Kenny", "They provide texture", "Jillian", "20 hp", "20", "37 lbs", "3", "Neither", "Morgan", "It's not unethical.", "6.78%", "What? I don't know that!?", "I don't have one", "Micronesia", "2018", "Synonymous with legendary", "Venezuela", "Y+", ".py", "Range-Based For", "The Assistance Bar", "$19.99 plus shipping and handling", "Gyroscope", "Line Sensor", "1337", "Cardi B", "A multi-classed array", "Unethical and cheating", "Pool" };
	int i;
	int size = prev_questions.size();
	do {
		i = rand() % questions.size();
		prev_questions.insert(i);
	} while (prev_questions.size() == size);
	q = questions.at(i);
	a1 = answer1r.at(i);
	a2 = answer2.at(i);
	a3 = answer3.at(i);
	a4 = answer4.at(i);
}

void RAT(sf::Font font,sf::RenderWindow& window, int& date, int& projectProgress, int& correct, int & totalQ) {
	totalQ++;
	sf::Text ratText("OOF! There's a RAT (Readiness Assessment Test) today \nHope you did the pre-class assignment...", font, 48);
	ratText.setFillColor(sf::Color::White);
	ratText.setPosition(10, 10);
	ratText.setOutlineThickness(3);
	ratText.setOutlineColor(sf::Color::Black);

	sf::Texture paper;
	if (!paper.loadFromFile("./linedpaper.jpg"))
	{
		// error...
		std::cout << "Error!\n";
	}
	sf::Sprite paperback(paper);
	paperback.setPosition(0, 0);
	paperback.setScale(.5, .5);

	const int buttonx = 400;
	sf::Event event;
	sf::Vector2f buttonSize = { 800,75 };
	sf::RectangleShape button1(buttonSize),button2(buttonSize),button3(buttonSize),button4(buttonSize);
	std::string question, answers[4];
	QA(question, answers[0], answers[1], answers[2], answers[3]);

	int placement = rand() % 4;

	sf::Text qtext(question, font, 48);
	qtext.setFillColor(sf::Color::White);
	qtext.setPosition(230,190);
	qtext.setOutlineThickness(3);
	qtext.setOutlineColor(sf::Color::Black);

	button1.setPosition(buttonx, 475);
	button1.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer1 = answers[placement];
	sf::Text text1(answer1, font, 48);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(buttonx+10, 475);

	button2.setPosition(buttonx, 575);
	button2.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer2 = answers[(placement + 1) % 4];
	sf::Text text2(answer2, font, 48);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(buttonx+10, 575);

	button3.setPosition(buttonx, 675);
	button3.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer3 = answers[(placement + 2) % 4];
	sf::Text text3(answer3, font, 48);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(buttonx+10, 675);

	button4.setPosition(buttonx, 775);
	button4.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer4 = answers[(placement + 3) % 4];
	sf::Text text4(answer4, font, 48);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(buttonx+10, 775);

	while (1) {
		window.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed) {
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (button1.getGlobalBounds().contains(localPositionF)) {
				if (answer1 == answers[0]) {
					button1.setFillColor(sf::Color::Green);
					correct++;
				}
				else {
					button1.setFillColor(sf::Color::Red);
				}
				break;
			}
			else if (button2.getGlobalBounds().contains(localPositionF)) {
				if (answer2 == answers[0]) {
					button2.setFillColor(sf::Color::Green);
					correct++;
				}
				else {
					button2.setFillColor(sf::Color::Red);
				}
				break;
			}
			else if (button3.getGlobalBounds().contains(localPositionF)) {
				if (answer3 == answers[0]) {
					button3.setFillColor(sf::Color::Green);
					correct++;
				}
				else {
					button3.setFillColor(sf::Color::Red);
				}
				break;
			}
			else if (button4.getGlobalBounds().contains(localPositionF)) {
				if (answer4 == answers[0]) {
					button4.setFillColor(sf::Color::Green);
					correct++;
				}
				else {
					button4.setFillColor(sf::Color::Red);
				}
				break;
			}
		}
		window.clear();
		window.draw(paperback);
		currentDate(date, font, window);
		drawProgress(projectProgress, font, window);
		window.draw(qtext);
		window.draw(ratText);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.display();
		
	}
	
	while (1) {
		window.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (drawNextButton(font,window).getGlobalBounds().contains(localPositionF)) {
				break;
			}
		}
		window.clear();
		window.draw(paperback);
		currentDate(date, font, window); 
		drawProgress(projectProgress, font, window);
		drawNextButton(font, window);
		window.draw(qtext);
		window.draw(ratText);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		
		
		window.display();
	
	}
	date++;
}
void CFU(sf::Font font, sf::RenderWindow& window, int& date, int projectProgress, int& correct, int & totalQ) {
	totalQ++;
	sf::Texture paper;
	if (!paper.loadFromFile("./engineeringpaper.jpg"))
	{
		// error...
		std::cout << "Error!\n";
	}
	sf::Sprite paperback(paper);
	paperback.setPosition(0, 0);
	paperback.setScale(2, 1.5);

	sf::Text ratText("CFU (Check for Understanding) good luck! \nYour scholarship depends on it", font, 48);
	ratText.setFillColor(sf::Color::Black);
	ratText.setPosition(10, 10);
	const int buttonx = 400;
	sf::Event event;
	sf::Vector2f buttonSize = { 800,75 };
	sf::RectangleShape button1(buttonSize), button2(buttonSize), button3(buttonSize), button4(buttonSize);
	std::string question, answers[4];
	QA(question, answers[0], answers[1], answers[2], answers[3]);

	int placement = rand() % 4;

	sf::Text qtext(question, font, 48);
	qtext.setFillColor(sf::Color::Black);
	qtext.setPosition(230, 190);


	button1.setPosition(buttonx, 475);
	button1.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer1 = answers[placement];
	sf::Text text1(answer1, font, 48);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(buttonx + 10, 475);

	button2.setPosition(buttonx, 575);
	button2.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer2 = answers[(placement + 1) % 4];
	sf::Text text2(answer2, font, 48);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(buttonx + 10, 575);

	button3.setPosition(buttonx, 675);
	button3.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer3 = answers[(placement + 2) % 4];
	sf::Text text3(answer3, font, 48);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(buttonx + 10, 675);

	button4.setPosition(buttonx, 775);
	button4.setFillColor(sf::Color::Color(50,50,50,255));
	std::string answer4 = answers[(placement + 3) % 4];
	sf::Text text4(answer4, font, 48);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(buttonx + 10, 775);

	while (1) {
		window.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed) {
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (button1.getGlobalBounds().contains(localPositionF)) {
				
				button1.setFillColor(sf::Color::Color(170,170,170,255));
				if (answer1 == answers[0]) {
					correct++;
				}
				
				break;
			}
			else if (button2.getGlobalBounds().contains(localPositionF)) {
				if (answer2 == answers[0]) {
					correct++;
				}
				button2.setFillColor(sf::Color::Color(170,170,170,255));
				
				break;
			}
			else if (button3.getGlobalBounds().contains(localPositionF)) {
				if (answer3 == answers[0]) {
					correct++;
				}
				button3.setFillColor(sf::Color::Color(170,170,170,255));
				
				break;
			}
			else if (button4.getGlobalBounds().contains(localPositionF)) {
				if (answer4 == answers[0]) {
					correct++;
				}
				button4.setFillColor(sf::Color::Color(170,170,170,255));
				
				break;
			}
		}
		window.clear();
		window.draw(paperback);
		currentDate(date, font, window); 
		drawProgress(projectProgress, font, window);
		window.draw(qtext);
		window.draw(ratText);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.display();

	}

	while (1) {
		window.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (drawNextButton(font, window).getGlobalBounds().contains(localPositionF)) {
				break;
			}
		}
		window.clear();
		window.draw(paperback);
		drawNextButton(font, window);
		currentDate(date, font, window);
		drawProgress(projectProgress, font, window);
		window.draw(qtext);
		window.draw(ratText);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.display();

	}
	date++;
}

void randEncounter(sf::Font font,sf::RenderWindow& window,int& date, int& projectProgress) {
	sf::Event event;
	std::string encMessage;
	sf::Texture classroom;
	if (!classroom.loadFromFile("./classroom.jpg"))
	{
		// error...
		std::cout << "Error!\n";
	}
	sf::Sprite classback(classroom);
	classback.setScale(1.1, 1.2);

	int enc = rand() % 8;
	switch (enc){
	case 0:
	case 1:
		encMessage = "No class today";
		break;
	case 2:
		encMessage = "One of your group members dropped out without telling anyone! \nYour progress is set back.";
		if (projectProgress > 0) {
			projectProgress--;
		}
		break;
	case 3:
	case 4:
		encMessage = "A random student shares vital information about the project with you.\nThank God...";
		if (projectProgress < 9) {
			projectProgress += 2;
		}
		else if (projectProgress == 9) {
			++projectProgress;
		}
		
		break;
	case 5:
		encMessage = "Your RFAI (Request for Additional Information) was actually helpful for once. \nYou now have a chance.";
		if (projectProgress < 10) {
			++projectProgress;
		}
		break;
	case 6:
		encMessage = "Too much homework and too little time! \nYou can't work on the project...";
		if (projectProgress > 0) {
			projectProgress--;
		}
	case 7:
		encMessage = "Your RFAI (Request for Additional Information) came back... \nIt didn't help at all";
		break;
	}
	
	sf::Text encText(encMessage, font, 48);
	encText.setFillColor(sf::Color::White);
	encText.setOutlineColor(sf::Color::Black);
	encText.setOutlineThickness(3);
	encText.setPosition(230, 190);

	while(1){
		window.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (drawNextButton(font, window).getGlobalBounds().contains(localPositionF)) {
				break;
			}
		}
		window.clear();
		window.draw(classback);
		drawNextButton(font, window);
		currentDate(date, font, window); 
		drawProgress(projectProgress, font, window);
		window.draw(encText);
		window.display();
	}
	
	
	date++;
}
void teamwork(sf::Font font, sf::RenderWindow& window, int& date, int& projectProgress) {
	sf::Event event;
	std::string teamMessage = "Your team meets up for a few hours to work on your robot";
	sf::Text teamText(teamMessage, font, 48);
	teamText.setFillColor(sf::Color::White);
	teamText.setPosition(230, 190);
	teamText.setOutlineColor(sf::Color::Black);
	teamText.setOutlineThickness(3);
	sf::Texture legos;
	if (!legos.loadFromFile("./legos.png"))
	{
		// error...
		std::cout << "Error!\n";
	}
	sf::Sprite legoback(legos);
	legoback.setScale(1.4, 1.2);
	legoback.setPosition(-20, -20);

	if (projectProgress < 10) {
		projectProgress++;
	}
	date++;

	while (1) {
		window.pollEvent(event);

		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
			if (drawNextButton(font, window).getGlobalBounds().contains(localPositionF)) {
				break;
			}
		}
		window.clear();
		window.draw(legoback);
		drawNextButton(font, window);
		currentDate(date, font, window);
		drawProgress(projectProgress, font, window);
		window.draw(teamText);
		window.display();
	}

}

int main()
{
	srand(time(NULL));
	sf::Music music;
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ENED Sim 2019");
	sf::Vector2f startSize = {300,100};
	sf::Texture texture1, texture2, kwuimy;
	sf::RectangleShape startButton(startSize);

	startButton.setPosition(1200, 100);
	startButton.setFillColor(sf::Color::Black);
	
	if (!music.openFromFile("./backgroundmusic.wav")) {
		return -1; //error
	}
	music.play();
	music.setLoop(true);
	if (!texture2.loadFromFile("./menuwithlogo.png"))
	{
		// error...
		std::cout << "Error!\n";
	}
	sf::Sprite background(texture2);
	
	sf::Font font;
	sf::Text startText("New Game",font,48);
	startText.setFillColor(sf::Color::White);
	startText.setPosition(1285, 115);
	
	

	if (!font.loadFromFile("Helvetica-UltraCompressed.ttf")) {
		std::cout << "error loading font file" << std::endl;
	}
	int projectProgress = 0;
	int gamestate = 0;
	int date = 5;
	int correct = 0;
	int totalQ = 0;
	bool end = false;
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		switch (gamestate) {
		case 0:
			
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
				if (startButton.getGlobalBounds().contains(localPositionF)) {
					gamestate = 1;
				}
			}
			
			window.draw(background);
			window.draw(startButton);
			window.draw(startText);
			break;
		case 1:
			window.clear();
			if (date > 29) {
				gamestate = 2;
			}
			else {
				int assignment = rand() % 4;
				switch (assignment) {
				case 0:
					RAT(font, window, date, projectProgress, correct, totalQ);
					break;
				case 1:
					CFU(font, window, date, projectProgress, correct, totalQ);
					break;
				case 2:
					teamwork(font, window, date, projectProgress);
					break;
				case 3:
					randEncounter(font, window, date, projectProgress);
					break;
				}
			}
			break;
		case 2:
			end = true;
			break;
		}
		window.display();
		if (end) {
			std::string endMessage1, endMessage2, endGrade;

			sf::Texture pk;
			if (!pk.loadFromFile("./pk.png"))
			{
				// error...
				std::cout << "Error!\n";
			}
			sf::Sprite pkimbrie(pk);
			pkimbrie.setPosition(-1000, -1000);
			pkimbrie.setScale(.4, .4);

			if (!kwuimy.loadFromFile("./croppedkwuimy.png"))
			{
				// error...
				std::cout << "Error!\n";
			}
			sf::Sprite endkwuimy(kwuimy);
			endkwuimy.setPosition(-1000, -1000);
			endMessage1 = "It's time for the project demo!\n";
			endGrade = "\nAlso you scored ";
			if (projectProgress >= 10) {
				
				int endcase = rand() % 5;
				
				switch (endcase) {
				case 0:
					endMessage2 = "You show up ready but some old guy knocks it out of your hands and it breaks!\nYou still get a B because of the curve.";
					break;
				case 1:
					endMessage2 = "Your teammates arrive with a working robot but\nthe floor was uneven and it couldn't walk!\nYou still get a B because of the curve.";
					break;
				case 2:
					endMessage2 = "Despite hours of testing, your robot breaks apart during the demo\nand can't finish!\nYou still get a B because of the curve.";
					break;
				case 3:
					endMessage2 = "Everything is set and the robot is doing great until the battery dies! \nYou still get a B because of the curve.";
					break;
				case 4:
					endMessage2 = "By some miracle your robot performs the task adequately... \nYou were the only team to get an A! \nKwuimy is impressed.";
					endkwuimy.setPosition(1150, 500);
					break;
				}

			}
			else {
				endMessage2 = "Too bad you aren't prepared... \nYou have failed ENED!";
				pkimbrie.setPosition(1150, 250);
			}

			endGrade += std::to_string(correct) + " out of " + std::to_string(totalQ) + " Questions correct.";
			
			endMessage1 += endMessage2 + endGrade;
			sf::Text endText(endMessage1, font, 70);
			endText.setFillColor(sf::Color::White);
			endText.setPosition(230, 190);

			while (1) {
				event.type = sf::Event::MouseButtonReleased;
				window.pollEvent(event);
				if (event.type == sf::Event::MouseButtonPressed) {
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					sf::Vector2f localPositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
					if (drawNextButton(font, window).getGlobalBounds().contains(localPositionF)) {
						break;
					}
				}
				window.clear();
				window.draw(pkimbrie);
				window.draw(endText);
				window.draw(endkwuimy);
				drawNextButton(font, window);
				
				window.display();
			}
			prev_questions.clear();
			projectProgress = 0;
			gamestate = 0;
			date = 5;
			correct = 0;
			totalQ = 0;
			end = false;
		}
	}
	return 0;
}


void currentDate(int date ,sf::Font font, sf::RenderWindow& window) {
	

	std::string days = "Day: ";
	std::string weeks = "Week: ";
	
	days += std::to_string(date % 5 + 1);
	weeks += std::to_string(date / 5);
	sf::Text currentday(days, font, 32);
	currentday.setFillColor(sf::Color::White);
	currentday.setOutlineThickness(3);
	currentday.setOutlineColor(sf::Color::Black);
	currentday.setPosition(SCREEN_WIDTH-105, 50);
	window.draw(currentday);

	sf::Text currentweek(weeks, font, 32);
	currentweek.setFillColor(sf::Color::White);
	currentweek.setOutlineThickness(3);
	currentweek.setOutlineColor(sf::Color::Black);
	currentweek.setPosition(SCREEN_WIDTH-120, 100);
	window.draw(currentweek);

}

void drawProgress(int projectProgress, sf::Font font, sf::RenderWindow& window) {
	std::string bar1 = "Project Progress: ";
	std::string bar3 = " / 10";
	bar1 += std::to_string(projectProgress);
	bar1 += bar3;

	sf::Text currentprogress(bar1, font, 32);
	currentprogress.setOutlineThickness(3);
	currentprogress.setOutlineColor(sf::Color::Black);
	currentprogress.setFillColor(sf::Color::White);
	currentprogress.setPosition(SCREEN_WIDTH - 400, 50);
	window.draw(currentprogress);

}