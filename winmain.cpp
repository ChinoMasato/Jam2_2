#include "DxLib.h"
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

//ページ追加の仕方
//ページの数字の代わりに下記enumにページ名を追加してください
//上から順番にページ番号が自動で割り振られます。
//例:PageA→0、PageB→1、PageC→2
enum
{
	PageTITLE,
	PageEXPLAIN,
	PageQ,//問題
	PageSYSTEM,//countstopを0にする場所
	PageA,//正解or不正解
	PageTIPS,//問題の解説（次のページでPageQに戻る）
	PageNULL,//繰り返しに必要なのりしろページ
	PageRESULT,//結果発表～！
	PageEND//終了～！
};

//問題の構造体
struct QU
{
	//問題の通し番号（0番から）
	int num;
	//問題文（最大7行）
	string sentence[7];
	//問題のイメージ画像の変数
	int Image_Graphic;
	//選択肢
	string choices[4];
	//正解
	char answer;
	//問題の解説（とりあえず最大3行）
	string tips[3];
};

//10問まで問題を代入できる
const int Question_No = 10;
QU Question[Question_No];

//今何問目？
int count_question = 0;

//問題をシャッフルするときに使う
QU For_Shuffle;

//正解画像の変数
int Correct_Graphic;

//不正解画像の変数
int Incorrect_Graphic;

//背景画像用の変数（箱）を用意
int Back_Graphic;//画像を入れておく変数				  

//タイトル画像用の変数（箱）を用意
int Title_Graphic;//画像を入れておく変数	

//エンディング画像用の変数（箱）を用意
int End_Graphic;//画像を入れておく変数	

//メッセージウィンドウ画像用の変数（箱）を用意
int Message_Graphic;//画像を入れておく変数

//カーソルの画像
int Select_Graphic;

//ゲームのページ数
int Page;

//ページめくりを止める為に使う
int Stop;

//PUSH ENTERの点滅に使う
int BlinkCounter;

//名前の色に使う
int NameColor;

//文字の色に使う
int TextColor;

//異なるフォントを使いたいときに必要
//int FontHandle[5];

//何番目の選択肢をさしているか
char Select = 'A';
int SelectStop;

int i = 0;

int update_count = 0;
//一度だけ実行したい処理に使う（0のときはオフ→実行する）
int countstop = 0;
int one_second = 144;

int select_time = 10;

//問題文を段落ごとに時間差で描画するときに使う
int draw_time = 0;

int score = 0;
int before_score = 0;
int combo = 0;

//正解しているか
bool correct = true;

void init()
{
	for (i = 0; i < Question_No; i++) {
		Question[i].num = { i };
	}
	for (i = 0; i < Question_No; i++) {
		//1問目　（日本梨）
		if (Question[i].num == 0)
		{
			//問題文
			Question[i].sentence[0] = "千葉県が栽培する日本梨で、";
			Question[i].sentence[1] = "おおよその収穫時期が";
			Question[i].sentence[2] = "７月下旬から８月中旬までの";
			Question[i].sentence[3] = "品種は次のうちどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：幸水";
			Question[i].choices[1] = "B：豊水";
			Question[i].choices[2] = "C：メロン";
			Question[i].choices[3] = "D：秋満月";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'A';

			//問題の解説
			Question[i].tips[0] = "千葉県の日本梨は、";
			Question[i].tips[1] = "産出額、栽培面積、収穫量が１位です。";
		}

		//2問目　（證誠寺）
		if (Question[i].num == 1)
		{
			//問題文
			Question[i].sentence[0] = "木更津市の證誠寺に伝わる伝説は、";
			Question[i].sentence[1] = "「日本三大■伝説」のひとつとして有名。";
			Question[i].sentence[2] = "■に入る動物は、次のうちどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：狐";
			Question[i].choices[1] = "B：蛇";
			Question[i].choices[2] = "C：狸";
			Question[i].choices[3] = "D：人間";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'C';

			//問題の解説
			Question[i].tips[0] = "證誠寺の「狸囃子伝説」を元とした";
			Question[i].tips[1] = "「證誠寺の狸囃子」という童謡があります。";
		}
		//3問目
		if (Question[i].num == 2)
		{
			//問題文
			Question[i].sentence[0] = "千葉県山武郡九十九里町で生まれた伊能忠敬は";
			Question[i].sentence[1] = "何をつくった？";
			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む
			//選択肢
			Question[i].choices[0] = "A：日本地図";
			Question[i].choices[1] = "B：醤油";
			Question[i].choices[2] = "C：びわ";
			Question[i].choices[3] = "D：望遠鏡";
			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'A';
			//問題の解説
			Question[i].tips[0] = "伊能忠敬は弟子たちとともに日本を歩き回り";
			Question[i].tips[1] = "日本地図を完成させた人物です。";
		}
		//4問目
		if (Question[i].num == 3)
		{
			//問題文
			Question[i].sentence[0] = "次のうちキッコーマンの";
			Question[i].sentence[1] = "スローガンはどれ？";
			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む
			//選択肢
			Question[i].choices[0] = "A：「深い味わいを。」";
			Question[i].choices[1] = "B：「おいしい記憶をつくりたい。」";
			Question[i].choices[2] = "C：「食卓に笑顔を。」";
			Question[i].choices[3] = "D：「頂点を、つかむ。」";
			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'B';
			//問題の解説
			Question[i].tips[0] = "「おいしい記憶をつくりたい。」このスローガンは日本国内向けで、";
			Question[i].tips[1] = "世界では「seasoning your life」を用いています。";
		}
		//5問目
		if (Question[i].num == 4)
		{
			//問題文
			Question[i].sentence[0] = "千葉県の郷土料理「なめろう」の材料　長ねぎ、しょうが、　";
			Question[i].sentence[1] = "しそ、味噌、あとひとつはどれ？";
			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む
			//選択肢
			Question[i].choices[0] = "A：サーモン";
			Question[i].choices[1] = "B：サバ";
			Question[i].choices[2] = "C：アジ";
			Question[i].choices[3] = "D：タイ";
			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'C';
			//問題の解説
			Question[i].tips[0] = "なめろうの食材には一年中獲れるアジが使われます。";
			Question[i].tips[1] = "他の魚だと、イワシ、サンマ、トビウオでもつくられます。";
		}
		//6問目（大根）
		if (Question[i].num == 5)
		{
			//問題文
			Question[i].sentence[0] = "次のうち、千葉県での生産量が";
			Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：いちじく";
			Question[i].choices[1] = "B：ぶり類";
			Question[i].choices[2] = "C：メロン";
			Question[i].choices[3] = "D：大根";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'D';

			//問題の解説
			Question[i].tips[0] = "国内産の落花生の8割は、";
			Question[i].tips[1] = "千葉県で生産されています。";
		}
		//7問目（龍角寺）
		if (Question[i].num == 6)
		{
			//問題文
			Question[i].sentence[0] = "千葉県の印旛沼付近に伝えられている";
			Question[i].sentence[1] = "龍伝承では、龍の体が３つに裂けて";
			Question[i].sentence[2] = "それぞれが落ちた場所に、";
			Question[i].sentence[3] = "龍腹寺、龍尾寺ができた。";
			Question[i].sentence[4] = "あと一つは？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：龍頭寺";
			Question[i].choices[1] = "B：龍焔寺";
			Question[i].choices[2] = "C：龍角寺";
			Question[i].choices[3] = "D：龍牙寺";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'C';

			//問題の解説
			Question[i].tips[0] = "龍角寺は千葉県印旛郡栄町に";
			Question[i].tips[1] = "あり、７世紀以上前に創建";
			Question[i].tips[2] = "された、関東屈指の古寺です。";
		}
		//8問目（落花生）
		if (Question[i].num == 7)
		{
			//問題文
			Question[i].sentence[0] = "次のうち、千葉県での生産量が";
			Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：Apple社";
			Question[i].choices[1] = "B：落花生";
			Question[i].choices[2] = "C：ふなっしー";
			Question[i].choices[3] = "D：すいか";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'B';

			//問題の解説
			Question[i].tips[0] = "国内産の落花生の8割は、";
			Question[i].tips[1] = "千葉県で生産されています。";
		}
		//9問目
		if (Question[i].num == 8)
		{
			//問題文
			Question[i].sentence[0] = "次のうち、千葉県での生産量が";
			Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：Apple社";
			Question[i].choices[1] = "B：落花生";
			Question[i].choices[2] = "C：メロン";
			Question[i].choices[3] = "D：すいか";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'B';

			//問題の解説
			Question[i].tips[0] = "国内産の落花生の8割は、";
			Question[i].tips[1] = "千葉県で生産されています。";
		}
		//10問目
		if (Question[i].num == 9)
		{
			//問題文
			Question[i].sentence[0] = "次のうち、千葉県での生産量が";
			Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

			Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

			//選択肢
			Question[i].choices[0] = "A：Apple社";
			Question[i].choices[1] = "B：落花生";
			Question[i].choices[2] = "C：メロン";
			Question[i].choices[3] = "D：すいか";

			//正解（A、B、C、Dのどれかを入力）
			Question[i].answer = 'B';

			//問題の解説
			Question[i].tips[0] = "国内産の落花生の8割は、";
			Question[i].tips[1] = "千葉県で生産されています。";
		}
	}
}

void shuffle()
{
	for (i = 0; i < Question_No; i++)
	{
		int r = rand() % Question_No;
		For_Shuffle = Question[r];
		Question[r] = Question[i];
		Question[i] = For_Shuffle;
	}
}

void draw()
{
	if (countstop == 0)
	{
		draw_time = 0;
		if (Page == PageQ)
		{
			select_time = 10;
		}
		if (Page == PageA && correct == true)
		{
			before_score = 15 + combo * 5 + select_time * 2;
			combo++;
		}
		if (Page == PageTIPS && correct == true)
		{
			score += before_score;
		}
		countstop = 1;
	}
	if (update_count % one_second == 0)
	{
		draw_time++;
	}

	//ゲーム説明
	if (Page == PageEXPLAIN)
	{
		if (draw_time >= 0)
		{
			DrawFormatString(250, 10, TextColor, "千葉県クイズ！");
		}
		if (draw_time >= 3)
		{
			DrawFormatString(250, 70, TextColor, "これから、千葉県に関するクイズを");
			DrawFormatString(250, 105, TextColor, "10問出題します！");
		}
		if (draw_time >= 6)
		{
			DrawFormatString(250, 140, TextColor, "連続で正解したり、素早く答えて正解すると");
			DrawFormatString(250, 175, TextColor, "スコアが大きく増えます！");
		}
		if (draw_time >= 9)
		{
			DrawFormatString(250, 210, TextColor, "なお、制限時間内に解答しなかった場合");
			DrawFormatString(250, 245, TextColor, "最後まで選択していたものが解答になります");
		}
		if (draw_time >= 12)
		{
			DrawFormatString(250, 280, TextColor, "めざせ！ハイスコア！");
		}
	}
	//問題文を描画する
	if (Page == PageQ)
	{
		DrawFormatString(0, 10, TextColor, "スコア %d 点", score);
		DrawFormatString(0, 45, TextColor, "制限時間 %d 秒", select_time);
		if (draw_time >= 0)
		{
			DrawFormatString(250, 10, TextColor, "第 %d 問", count_question + 1);
		}
		if (draw_time >= 3)
		{
			DrawFormatString(250, 45, TextColor, "%s", Question[count_question].sentence[0].c_str());
		}
		if (draw_time >= 6)
		{
			DrawFormatString(250, 80, TextColor, "%s", Question[count_question].sentence[1].c_str());
		}
		if (draw_time >= 9)
		{
			DrawFormatString(250, 115, TextColor, "%s", Question[count_question].sentence[2].c_str());
		}
		if (draw_time >= 12)
		{
			DrawFormatString(250, 150, TextColor, "%s", Question[count_question].sentence[3].c_str());
		}
		//選択肢表示
		if (draw_time >= 15 && select_time > 0)
		{
			if (update_count % one_second == 0)
			{
				select_time--;
			}
			//カーソルを描画
			if (Select == 'A')
			{
				DrawFormatString(60, 450, TextColor, "⇒");
			}
			if (Select == 'B')
			{
				DrawFormatString(310, 450, TextColor, "⇒");
			}
			if (Select == 'C')
			{
				DrawFormatString(60, 480, TextColor, "⇒");
			}
			if (Select == 'D')
			{
				DrawFormatString(310, 480, TextColor, "⇒");
			}
			//Aの選択肢
			DrawFormatString(110, 450, TextColor, "%s", Question[count_question].choices[0].c_str());
			//Bの選択肢
			DrawFormatString(360, 450, TextColor, "%s", Question[count_question].choices[1].c_str());
			//Cの選択肢
			DrawFormatString(110, 480, TextColor, "%s", Question[count_question].choices[2].c_str());
			//Dの選択肢
			DrawFormatString(360, 480, TextColor, "%s", Question[count_question].choices[3].c_str());
		}
		if (select_time <= 0)
		{
			select_time = 10;
			Page++;
		}
	}
	//正解か、不正解かを表示
	if (Page == PageA)
	{
		DrawFormatString(0, 10, TextColor, "スコア %d 点", score);
		DrawFormatString(0, 45, TextColor, "制限時間 %d 秒", select_time);
		if (combo >= 2)
		{
			DrawFormatString(250, 80, TextColor, "%d 問連続正解！", combo);
		}
		if (Select == Question[count_question].answer)
		{
			correct = true;
			DrawFormatString(250, 10, TextColor, "正解！");
			DrawFormatString(250, 45, TextColor, "スコア %d 点獲得！", before_score);
		}
		else {
			correct = false;
			combo = 0;
			DrawFormatString(250, 10, TextColor, "不正解！");
		}
	}
	//解説を表示
	if (Page == PageTIPS)
	{
		DrawFormatString(0, 10, TextColor, "スコア %d 点", score);
		DrawFormatString(250, 10, TextColor, "正解は");
		if (Question[count_question].num == 0)
		{
			DrawFormatString(250, 45, TextColor, "A：幸水");
		}
		if (Question[count_question].num == 1)
		{
			DrawFormatString(250, 45, TextColor, "C：狸");
		}
		if (Question[count_question].num == 2)
		{
			DrawFormatString(250, 45, TextColor, "");
		}
		if (Question[count_question].num == 3)
		{
			DrawFormatString(250, 45, TextColor, "");
		}
		if (Question[count_question].num == 4)
		{
			DrawFormatString(250, 45, TextColor, "");
		}
		if (Question[count_question].num == 5)
		{
			DrawFormatString(250, 45, TextColor, "D：大根");
		}
		if (Question[count_question].num == 6)
		{
			DrawFormatString(250, 45, TextColor, "C：龍角寺");
		}
		if (Question[count_question].num == 7)
		{
			DrawFormatString(250, 45, TextColor, "B：落花生");
		}
		if (Question[count_question].num == 8)
		{
			DrawFormatString(250, 45, TextColor, "");
		}
		if (Question[count_question].num == 9)
		{
			DrawFormatString(250, 45, TextColor, "");
		}
		DrawFormatString(250, 80, TextColor, "%s", Question[count_question].tips[0].c_str());
		DrawFormatString(250, 115, TextColor, "%s", Question[count_question].tips[1].c_str());
		DrawFormatString(250, 150, TextColor, "%s", Question[count_question].tips[2].c_str());
	}
	//問題のイメージ画像を描画
	DrawGraph(0, 0, Question[count_question].Image_Graphic, true);
	//結果発表～！
	if (Page == PageRESULT)
	{
		if (draw_time >= 0)
		{
			DrawFormatString(250, 10, TextColor, "成績発表！");
		}
		if (draw_time >= 2)
		{
			DrawFormatString(250, 45, TextColor, "あなたのスコアは... %d 点！", score);
		}
	}
}

void timer()
{
	update_count++;
}

//最初に1回呼ばれる処理
void Start()
{
	srand(time(0));

	init();
	//shuffle();

	//フォント0、25ピクセル
	//FontHandle[0] = CreateFontToHandle(NULL, 25, 3);
	//フォント1、40ピクセル
	//FontHandle[1] = CreateFontToHandle(NULL, 40, 3);

	Back_Graphic = LoadGraph("back_test_02.jpg");//学校画像を変数に読み込む
	Title_Graphic = LoadGraph("title.jpg");//タイトル画像を変数に読み込む
	End_Graphic = LoadGraph("end.png");//タイトル画像を変数に読み込む
	Message_Graphic = LoadGraph("message_window_test.png");//メッセージウィンドウ用画像を変数に読み込む

	Page = 0;//0ページ目からストーリーを進める
	Stop = 0;//0は止めない、1は止める
	Select = 'A';
	BlinkCounter = 0;
	// 描画する文字列のサイズを設定
	SetFontSize(25);

	//NameColor = GetColor(255, 255, 255);//名前は白で書く
	TextColor = GetColor(255, 255, 255);//文字は白で書く

	//BGM再生
	PlayMusic("bgm_maoudamashii_neorock71b.mp3", DX_PLAYTYPE_LOOP);
}

//毎フレーム呼ばれる処理
void Update()
{
	timer();

	//デバッグ用
	//DrawFormatString(550, 100, TextColor, "何問目？ %d", count_question);

	//キーを押してページをめくる処理
	//エンターキー(KEY_INPUT_RETURN)が押されたらページを進める
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && Stop == 0)
	{
		Page = Page + 1;//シナリオを1ページ進める
		if (Page >= PageEND)
		{
			Page = PageTITLE;
		}
		Stop = 1;//キーを押し続けた時に連続でページが進まないようにする
	}

	//下キーが入力された時に選択肢カーソルを下に動かす（SelectNo変数を1増やす)
	if (CheckHitKey(KEY_INPUT_DOWN) == 1
		&& SelectStop == 0)
	{
		if (Select == 'A')
		{
			Select = 'C';
		}
		if (Select == 'B')
		{
			Select = 'D';
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}

	//上キーが入力された時に選択肢カーソルを上に動かす（SelectNo変数を1減らす)
	if (CheckHitKey(KEY_INPUT_UP) == 1
		&& SelectStop == 0)
	{
		if (Select == 'C')
		{
			Select = 'A';
		}
		if (Select == 'D')
		{
			Select = 'B';
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}

	//右キーが入力された時に選択肢カーソルを右に動かす（SelectNo変数を1増やす)
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1
		&& SelectStop == 0)
	{
		if (Select == 'A')
		{
			Select = 'B';
		}
		if (Select == 'C')
		{
			Select = 'D';
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}

	//左キーが入力された時に選択肢カーソルを左に動かす（SelectNo変数を1減らす)
	if (CheckHitKey(KEY_INPUT_LEFT) == 1
		&& SelectStop == 0)
	{
		if (Select == 'B')
		{
			Select = 'A';
		}
		if (Select == 'D')
		{
			Select = 'C';
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}

	//エンターキーが押されて居なければストップを解除する
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		//Stopを解除
		Stop = 0;
	}
	//下キーも上キーも右キーも左キーも押されていなければ連続キー入力停止処理を解除
	if (CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_UP) == 0
		&& CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0)
	{
		//Stopを解除
		SelectStop = 0;
	}

	//選択肢判定ページ
	//ページをジャンプさせる処理
	/*if (Page == PageQ)
	{
		if (SelectNo == 0) {
			Page = PageA;
		}
		if (SelectNo == 1) {
			Page = PageA;
		}
		if (SelectNo == 2) {
			Page = PageA;
		}
	}*/

	//ページごとにゲーム画面を表示する処理
	//1ページ目の場合の処理
	if (Page == PageTITLE)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Title_Graphic, true);

		if (BlinkCounter / 20 % 2 == 0) {
			DrawFormatString(300, 300, TextColor, "PUSH ENTER");
			//DrawStringToHandle(300, 10, "PUSH ENTER", TextColor, FontHandle[0]);
		}
		BlinkCounter = BlinkCounter + 1;
	}

	//1ページ目の場合の処理
	if (Page == PageEXPLAIN)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		//DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウにテキストを表示する
		draw();
	}
	//4ページ目の場合の処理
	if (Page == PageQ)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Back_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		//DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウにテキストを表示する
		draw();
	}
	if (Page == PageSYSTEM)
	{
		countstop = 0;
		Page++;
	}
	//5ページ目の処理
	if (Page == PageA)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Back_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		//DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウにテキストを表示する
		draw();
	}
	//6ページ目の場合の処理
	if (Page == PageTIPS)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Back_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		//DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウにテキストを表示する
		draw();
	}

	//7ページ目の処理
	if (Page == PageNULL)
	{
		if (count_question < Question_No)
		{
			countstop = 0;
			count_question++;
			Page = PageQ;
		}
		if (count_question >= Question_No)
		{
			Page++;
		}
	}

	//8ページ目の場合の処理
	if (Page == PageRESULT)
	{
		// 画面に背景を描画します。
		//DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		//DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウにテキストを表示する
		draw();
	}
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

	Start();//最初に１回呼ぶ

	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		Update();//毎回呼ぶ

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}

	for (i = 0; i < Question_No; i++) {
		DeleteGraph(Question[i].Image_Graphic);
	}
	DeleteGraph(Title_Graphic);
	DeleteGraph(Back_Graphic);
	DeleteGraph(Message_Graphic);
	DeleteGraph(End_Graphic);

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

