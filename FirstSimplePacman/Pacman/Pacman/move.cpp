



using namespace std;

void getKeyPress();
void movePac(int _X, int _Y);

int main()
{
	getKeyPress();
	return 0;
}
void getKeyPress()

{
	bool yam = true;
	while (yam)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (checkUp(x, y + 1))
			{
				movePac(x, y + 1);
			}
		}
		else if (GetAsyncKeyState(VK_DOWN)
		{
			if (checkDoun(x, y - 1))
			{
				movePac(x, y - 1);
			}
		}
		else if (VK_LEFT)
		{
			if (checkLeft(x - 1, y))
			{
				movePac(x - 1, y);
			}
		}
		else if (VK_RIGHT)
		{
			if (checkRight(x + 1, y))
			{
				movePac(x + 1, y);
			}
		}
	}
}

//===========================================================
void movePac(int _X, int _Y)
{
	גטורטקס = _X;
	גטורטקס = _Y;
}

//==============================================================
bool checkUp(int x, int y)
{
}
//--------------------------------------------------------------
bool checkDown(int x, int y)
{
}
//--------------------------------------------------------------
bool checkLeft(int x, int y)
{
}
//------------------------------------------------------------------
bool checkRight(int x, int y)
{
}
//=================================================================
/*if (levelMatrix[pacI - 1][pacJ] != WALL)

{

		if (levelMatrix[pacI - 1][pacJ] == POWERPILL)

		{

				startTime = clock();

				superPellet = true;

		}

		levelMatrix[pacI][pacJ] = BLANK;
	*/
levelMatrix[pacI - 1][pacJ] = PACMANUP;

pacI--;

}

		}

		else if (GetAsyncKeyState(VK_LEFT)) //left

		{

			if (levelMatrix[pacI][pacJ - 1] != WALL)

			{

				if (levelMatrix[pacI][pacJ - 1] == POWERPILL)

				{

					startTime = clock();

					superPellet = true;

				}

				levelMatrix[pacI][pacJ] = BLANK;

				levelMatrix[pacI][pacJ - 1] = PACMANLEFT;

				pacJ--;

			}

		}

		else if (GetAsyncKeyState(VK_RIGHT)) //right

		{

			if (levelMatrix[pacI][pacJ + 1] != WALL)

			{

				if (levelMatrix[pacI][pacJ + 1] == POWERPILL)

				{

					startTime = clock();

					superPellet = true;

				}

				levelMatrix[pacI][pacJ] = BLANK;

				levelMatrix[pacI][pacJ + 1] = PACMANRIGHT;

				pacJ++;

			}

		}

		else if (GetAsyncKeyState(VK_DOWN)) //down

		{

			if (levelMatrix[pacI + 1][pacJ] != WALL)

			{

				if (levelMatrix[pacI + 1][pacJ] == POWERPILL)

				{

					startTime = clock();

					superPellet = true;

				}

				levelMatrix[pacI][pacJ] = BLANK;

				levelMatrix[pacI + 1][pacJ] = PACMANDOWN;

				pacI++;

			}

		}

}


