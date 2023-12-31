int hexToDecimal(string hexNum) {
	int decNum = 0;
	char c;
	int digit = 0;
	int until = hexNum.length();

	for (int i = 0; i < until; i++) {
		c = hexNum[hexNum.length() - 1];
		switch (c)
		{
		case '0':
			digit = 0;
			break;
		case '1':
			digit = 1;
			break;
		case '2':
			digit = 2;
			break;
		case '3':
			digit = 3;
			break;
		case '4':
			digit = 4;
			break;
		case '5':
			digit = 5;
			break;
		case '6':
			digit = 6;
			break;
		case '7':
			digit = 7;
			break;
		case '8':
			digit = 8;
			break;
		case '9':
			digit = 9;
			break;
		case 'A':
			digit = 10;
			break;
		case 'B':
			digit = 11;
			break;
		case 'C':
			digit = 12;
			break;
		case 'D':
			digit = 13;
			break;
		case 'E':
			digit = 14;
			break;
		case 'F':
			digit = 15;
			break;
		case 'a':
			digit = 10;
			break;
		case 'b':
			digit = 11;
			break;
		case 'c':
			digit = 12;
			break;
		case 'd':
			digit = 13;
			break;
		case 'e':
			digit = 14;
			break;
		case 'f':
			digit = 15;
			break;
		default:
			break;
		}
		hexNum.pop_back();
		decNum += digit * pow(16, i);
	}

	return decNum;
}