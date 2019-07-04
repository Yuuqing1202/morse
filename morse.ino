＃包括 < Morse.h >

莫尔斯莫尔斯（13）;

//定义莫尔斯电码表
char MORSE [] [ 4 ] = {
  { '.','-','*','*' }，// A
  { '-','.','.','.' }，// B
  { '-','.','-','.' }，// C
  { '-','.','.','*' }，// D
  { '.','*','*','*' }，// E
  { '.','.','-','.' }，// F
  { '-','-','.','*' }，// G
  { '.','.','.','.' }，// H
  { '.','.','*','*' }，//我
  { '.','-','-','-' }，// J
  { '-','.','-','*' }，// K
  { '.','-','.','.' }，// L
  { '-','-','*','*' }，// M
  { '-','.','*','*' }，// N
  { '-','-','-','*' }，// O.
  { '.','-','-','.' }，// P
  { '-','-','.','-' }，// Q
  { '.','-','.','*' }，// R
  { '.','.','.','*' }，// S
  { '-','*','*','*' }，// T
  { '.','.','-','*' }，// U
  { '.','.','.','-' }，// V
  { '.','-','-','*' }，// W
  { '-','.','.','-' }，// X.
  { '-','.','-','-' }，// Y.
  { '-','-','.','.' },  // Z
};

void  setup（）
{
  串行。开始（9600）; //设置通信波特率
}

void  loop（）
{
  String str = “ ” ;  //定义未转义字符串
  String morse_s = “ ” ;  //定义转义后字符串
  int i，t，temp = 0 ;
  int n = 0 ;  //对传入字符个数计数
  而（串行。可用的（）> 0）
  {
    temp = 1 ;  //判断是否有数据传入
    STR + = 炭（串行。读（））;  //将传入的数据储存在字符串中
    延迟（2）;  //延迟保证传入正常
    的n ++;
  }

  if（temp）
  {
    //查询莫尔斯电码表并进行转换
    for（i = 0 ; i <n; i ++）
    {
      //判断是否为小写字母，如果是则转义
      if（str [i]> = 97 && str [i] <= 122）
      {
        for（t = 0 ; t < 4 ; t ++）
        {
          morse_s + = char（MORSE [ int（str [i]  - 97）] [t]）;
        }
      }
      //每段莫尔斯之后补斜杠（表字母结束）或空格（表单词结束）
      if（int（str [i]）！= 32）{morse_s + = ' / ' ;}
      别的 {morse_s + = '  ' ;}
    }
    串行。println（morse_s）;  //串口传出
    for（i = 0 ; morse_s [i]！= ' \ 0 ' ; i ++）//从头到尾读取莫尔、斯电码
    {
      如果（morse_s [i] == '。'）莫尔斯。dot（）;
      否则 如果（morse_s [i] == ' - '）莫尔斯。dash（）;
      否则 如果（morse_s [i] == '  '）莫尔斯。w_space（）;
      否则 如果（morse_s [i] == ' / '）莫尔斯。c_space（）;
    }
    串行。println（“发送完毕”）;
    延迟（2）;
  }
}