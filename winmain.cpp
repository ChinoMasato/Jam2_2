#include "DxLib.h"

//ページ追加の仕方
//ページの数字の代わりに下記enumにページ名を追加してください
//上から順番にページ番号が自動で割り振られます。
//例:PageA→0、PageB→1、PageC→2
enum
{
	PageA,
	PageB,
	PageC,
	PageD,
	PageE,
	PageF,
	PageG,
	PageH,
	PageI,
	PageI2,
	PageJ,
	PageK,
	PageL,
	PageM,
	PageM2,
	PageN,
	PageO,
	PageO2,
	PageP,
	PageQ,
	PageR,
	PageS,
	PageEND
};
//授業始まるってよ。
//
//

//立木先生画像用の変数（箱）を用意
int Tachiki_Graphic;//画像を入れておく変数

//柴田先生画像用の変数（箱）を用意
int Shibata_Graphic;//画像を入れておく変数

//山田先生画像用の変数（箱）を用意
int Yamada_Graphic;//画像を入れておく変数

//佐久間先生画像用の変数（箱）を用意
int Sakuma_Graphic;//画像を入れておく変数

//植田先生画像用の変数（箱）を用意
int Ueda_Graphic;//画像を入れておく変数

//千野先生画像用の変数（箱）を用意
int Chino_Graphic;//画像を入れておく変数

//背景画像用の変数（箱）を用意
int Back_Graphic;//画像を入れておく変数				  

//タイトル画像用の変数（箱）を用意
int Title_Graphic;//画像を入れておく変数	

//エンディング画像用の変数（箱）を用意
int End_Graphic;//画像を入れておく変数	

//メッセージウィンドウ画像用の変数（箱）を用意
int Message_Graphic;//画像を入れておく変数		

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

//何番目の選択肢をさしているか
int SelectNo = 0;
int SelectStop;

//最初に1回呼ばれる処理
void Start()
{
	Tachiki_Graphic = LoadGraph("tachiki.png");//立木先生画像を変数に読み込む
	Shibata_Graphic = LoadGraph("shibata.png");//柴田先生画像を変数に読み込む
	Yamada_Graphic = LoadGraph("yamada.png");//山田先生画像を変数に読み込む
	Sakuma_Graphic = LoadGraph("sakuma.png");//佐久間先生画像を変数に読み込む
	Ueda_Graphic = LoadGraph("ueda.png");//植田先生画像を変数に読み込む
	Chino_Graphic = LoadGraph("chino.png");//千野先生画像を変数に読み込む
	Back_Graphic = LoadGraph("itc2.jpg");//学校画像を変数に読み込む
	Title_Graphic = LoadGraph("title.jpg");//タイトル画像を変数に読み込む
	End_Graphic = LoadGraph("end.png");//タイトル画像を変数に読み込む
	Message_Graphic = LoadGraph("frame_message.png");//メッセージウィンドウ用画像を変数に読み込む

	Page = 0;//0ページ目からストーリーを進める
	Stop = 0;//0は止めない、1は止める
	SelectNo = 0;
	BlinkCounter = 0;
	// 描画する文字列のサイズを設定
	SetFontSize(24);

	NameColor = GetColor(255, 255, 255);//名前は白で書く
	TextColor = GetColor(0, 0, 0);//文字は黒で書く

	//BGM再生
	PlayMusic("bgm_maoudamashii_neorock71b.mp3", DX_PLAYTYPE_LOOP);
}

//毎フレーム呼ばれる処理
void Update()
{
	//キーを押してページをめくる処理
	//エンターキー(KEY_INPUT_RETURN)が押されたらページを進める
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && Stop == 0)
	{
		Page = Page + 1;//シナリオを1ページ進める
		if (Page >= PageEND)
		{
			Page = PageA;
		}
		Stop = 1;//キーを押し続けた時に連続でページが進まないようにする
	}

	//下キーが入力された時に選択肢カーソルを下に動かす（SelectNo変数を1増やす)
	if (CheckHitKey(KEY_INPUT_DOWN) == 1
		&& SelectStop == 0)
	{
		SelectNo = SelectNo + 1;
		if (SelectNo > 2)
		{
			SelectNo = 2;
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}

	//上キーが入力された時に選択肢カーソルを上に動かす（SelectNo変数を1減らす)
	if (CheckHitKey(KEY_INPUT_UP) == 1
		&& SelectStop == 0)
	{
		SelectNo = SelectNo - 1;
		if (SelectNo < 0)
		{
			SelectNo = 0;
		}
		SelectStop = 1;//連続でカーソルが進まないようにする
	}
	//エンターキーが押されて居なければストップを解除する
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		//Stopを解除
		Stop = 0;
	}
	//下キーも上キーも押されていなければ連続キー入力停止処理を解除
	if (CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_UP) == 0)
	{
		//Stopを解除
		SelectStop = 0;
	}

	//選択肢判定ページ
	//ページをジャンプさせる処理
	if (Page == PageG)
	{
		if (SelectNo == 0) {
			Page = PageH;
		}
		if (SelectNo == 1) {
			Page = PageL;
		}
		if (SelectNo == 2) {
			Page = PageO;
		}
	}
	if (Page == PageI2)
	{
		Page = PageF;
	}
	if (Page == PageM2) {
		Page = PageF;
	}
	if (Page == PageO2) {
		Page = PageF;
	}


	//ページごとにゲーム画面を表示する処理
	//1ページ目の場合の処理
	if (Page == PageA)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Title_Graphic, true);

		if (BlinkCounter / 20 % 2 == 0) {
			DrawFormatString(235, 360, TextColor, "PUSH ENTER");
		}
		BlinkCounter = BlinkCounter + 1;
	}

	//1ページ目の場合の処理
	if (Page == PageB)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "ここが、国際理工情報デザイン専門学校か\nどんな先生がいるんだろう\n不安だなぁ…");
	}
	//2ページ目の場合の処理
	if (Page == PageC)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "！？\n向こうからやけにテンションが高い人が来た！");
	}
	if (Page == PageD) {
		StopMusic();
		PlaySoundFile("se.mp3", DX_PLAYTYPE_BACK);
		PlayMusic("bgm_maoudamashii_neorock83.mp3", DX_PLAYTYPE_LOOP);
		Page = Page + 1;
	}

	//4ページ目の場合の処理
	if (Page == PageE)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Tachiki_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "立木 健太郎");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "イェーイ！マヤサイコー！\nスリーディメンション！！\n３つのＤ！３つのRe！３つのK！\n");
	}

	//4ページ目の場合の処理
	if (Page == PageF)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "選択してください");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(70, 440, TextColor, "山田先生ルート");
		DrawFormatString(70, 470, TextColor, "柴田先生ルート");
		DrawFormatString(70, 500, TextColor, "植田先生ルート");
		DrawFormatString(40, 440 + 30 * SelectNo, TextColor, "⇒");
	}

	//5ページ目の処理
	if (Page == PageH)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Yamada_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "山田 龍明");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "突然だけど21時からAPEXやらない？\n気楽にやろう\n配信もしちゃうよ！\n");
	}
	//6ページ目の場合の処理
	if (Page == PageI)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "いきなりゲームに誘ってきた！っていうかまだ午前中\nＰＳ４版ならやったんだけど…");
	}

	//7ページ目の処理
	if (Page == PageJ)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Sakuma_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "佐久間 洋");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "私と勝負しよう\n腕相撲、格ゲー、そしてぷよぷよで\n私に勝ったらここを通してあげよう");
	}
	//8ページ目の場合の処理
	if (Page == PageK)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "エンターキーを押しただけで通してくれた！\n次はふらっと誰かが来たぞ");
	}

	//9ページ目の処理
	if (Page == PageL)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Shibata_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "柴田 大地");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "２次元の世界に行く方法を知っているかい？\nふらっと行けばいいんだよ。\n平面だけにね。ハハハハハ");
	}

	//10ページ目の処理
	if (Page == PageM)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "２次元ギャグをぶっこんできた！\nこれはこのプログラムの作者に無理やりキャラ付けされたに違いない\n");
	}

	//11ページ目の処理
	if (Page == PageN)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Chino_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "千野 正登");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "柴田先生には業務が忙しい中\n画像の透過、縮小処理をしていただきました。\nありがとうございました。");
	}

	//12ページ目の処理
	if (Page == PageO)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)
		DrawGraph(200, 10, Ueda_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "植田 勉");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "こんにちは植田です。\n6月の授業から先生達をよろしく！");
	}

	//13ページ目の場合の処理
	if (Page == PageP)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);

		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "今まで現れたやばい人たちが\nこの学校の先生！！？");
	}

	//14ページ目の処理
	if (Page == PageQ)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)

		DrawGraph(0, 10, Chino_Graphic, true);
		DrawGraph(190, 0, Yamada_Graphic, true);
		DrawGraph(100, 10, Sakuma_Graphic, true);
		DrawGraph(420, 10, Shibata_Graphic, true);
		DrawGraph(500, 10, Ueda_Graphic, true);
		DrawGraph(300, 10, Tachiki_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "やばい先生ばかりだけど、楽しい学校生活が始まりそうな\n\n　　　　　　　　　　　　　予感！！\n");
	}

	//15ページ目の処理
	if (Page == PageR)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, End_Graphic, true);
	}

	//16ページ目の処理
	if (Page == PageS)
	{
		// 画面に背景を描画します。
		DrawGraph(0, 0, Back_Graphic, true);
		// 画面にキャラを描画します(『DrawGraph』を使用)

		DrawGraph(0, 10, Chino_Graphic, true);
		DrawGraph(190, 0, Yamada_Graphic, true);
		DrawGraph(100, 10, Sakuma_Graphic, true);
		DrawGraph(420, 10, Shibata_Graphic, true);
		DrawGraph(500, 10, Ueda_Graphic, true);
		DrawGraph(300, 10, Tachiki_Graphic, true);
		//画面にメッセ―ジウィンドウを描画します
		DrawGraph(0, 360, Message_Graphic, true);
		//メッセージウィンドウに名前を表示する
		DrawFormatString(60, 385, NameColor, "？？？？");
		//メッセージウィンドウにテキストを表示する
		DrawFormatString(40, 440, TextColor, "やばい先生ばかりだけど、楽しい学校生活が始まりそうな\n\n　　　　　　　　　　　　　予感！！\n");
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

	DeleteGraph(Tachiki_Graphic);
	DeleteGraph(Yamada_Graphic);
	DeleteGraph(Shibata_Graphic);
	DeleteGraph(Chino_Graphic);
	DeleteGraph(Sakuma_Graphic);
	DeleteGraph(Ueda_Graphic);
	DeleteGraph(Title_Graphic);
	DeleteGraph(Back_Graphic);
	DeleteGraph(Message_Graphic);
	DeleteGraph(End_Graphic);

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

