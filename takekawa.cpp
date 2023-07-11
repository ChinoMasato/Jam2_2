//6問目
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
//7問目
if (Question[i].num == 6)
{
	//問題文
	Question[i].sentence[0] = "";
	Question[i].sentence[1] = "";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：";
	Question[i].choices[1] = "B：";
	Question[i].choices[2] = "C：";
	Question[i].choices[3] = "D：";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'C';

	//問題の解説
	Question[i].tips[0] = "";
	Question[i].tips[1] = "千";
}
//8問目
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