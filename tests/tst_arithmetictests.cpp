#include <QtTest>
#include <bigint.h>
#include <limits>
#include <random>

// add necessary includes here

class arithmetictests : public QObject
{
    Q_OBJECT

public:
    arithmetictests();
    ~arithmetictests();

private slots:
    void arithmeticAssignmentAdditionTest();
    void arithmeticAssignmentSubtractionTest();
    void arithmeticAssignmentMultiplicationTest();
    void arithmeticAssignmentDivisionTest();
    void arithmeticAssignmentModuloTest();

    // Binary arithmetic operations on BigInts with integers, strings and BigInts
    void binaryArithmeticWithIntStrBigTest();

    // Binary arithmetic operations with zeroes
    void binaryArithmeticWith0Test();

    // Chaining addition and subtraction
    void binaryArithmeticAddSubTest();

    // Chaining multiplication, division and modulo
    void binaryArithmeticDivModTest();

    // Addition of big numbers
    void binaryArithmeticBigTest();

    // Subtraction of big numbers
    void binaryArithmeticSubtractionBigTest();

    // Multiplication of big numbers
    void binaryArithmeticMultiplicationBigTest();

    // Base cases for division
    void binaryArithmeticBaseDivTest();

    // Division of big numbers
    void binaryArithmeticBigDivTest();

    // Base cases for modulo
    void binaryArithmeticBaseModTest();

    // Modulo of big numbers
    void binaryArithmeticBigModTest();

    // test increment operators
    void incrementTest();

    // test decrement operators
    void decrementTest();

    // Relational operators
    void relationalOperatorsTest();

    // Relational operators with BigInts and integers or strings
    void relationalOperatorsBigIntsTest();

    // Relational operators with BigInts and integers or strings
    void shiftingTest();

    // test binary operations
    void binTest();

    void testOperators();

    void constructorsTest();

};

arithmetictests::arithmetictests() {

}

arithmetictests::~arithmetictests() {

}

void arithmetictests::constructorsTest() {
    BigInt num1;        // should be 0 by default
    QVERIFY(num1 == 0);

    BigInt num2 (0);     // 0 passed as an integer
    QVERIFY(num2 == 0);

    BigInt num3("0");   // 0 passed as a string
    QVERIFY(num3 == 0);

    BigInt num4(num3);  // object with value 0 passed to copy constructor
    QVERIFY(num4 == 0);

    BigInt num5(0.0);  // object with value 0 passed to copy constructor
    QVERIFY(num5 == 0);

    // inversion
    BigInt num21(1.0);
    QVERIFY(num21 != 0);

    BigInt num31("1");
    QVERIFY(num31 != 0);

    BigInt num41(num31);
    QVERIFY(num41 != 0);

    BigInt num51(1.0);
    QVERIFY(num51 != 0);

}

void arithmetictests::arithmeticAssignmentAdditionTest() {
    BigInt num1, num2, num3;
    num1 = "85241964353410";
    num2 = "617705612502427";
    num3 += num1;
    QVERIFY(num3 == "85241964353410");
    num3 += num2;
    QVERIFY(num3 == "702947576855837");
    num3 += num1 + num2;
    QVERIFY(num3 == "1405895153711674");
    num3 += 0;
    QVERIFY(num3 == "1405895153711674");
    num3 += 1234567890;
    QVERIFY(num3 == "1405896388279564");
    num3 += "12345678909876543210";
    QVERIFY(num3 == "12347084806264822774");


}

void arithmetictests::arithmeticAssignmentSubtractionTest() {
    BigInt num1, num2, num3;
    num1 = "169523540030343";
    num2 = "849991085752380";
    num3 -= num1;
    QVERIFY(num3 == "-169523540030343");
    num3 -= num2;
    QVERIFY(num3 == "-1019514625782723");
    num3 -= -(num1 + num2);
    QVERIFY(num3 == 0);
    num3 -= 0;
    QVERIFY(num3 == 0);
    num3 -= 1234567890;
    QVERIFY(num3 == -1234567890);
    num3 -= "12345678909876543210";
    QVERIFY(num3 == "-12345678911111111100");
}

void arithmetictests::arithmeticAssignmentMultiplicationTest() {
    BigInt num1, num2, num3;
    num1 = "169523540030343";
    num2 = "849991085752380";
    num3 = 1;

    num3 *= num1;
    QVERIFY(num3 == "169523540030343");
    num3 *= num2;
    QVERIFY(num3 == "144093497850978300540184466340");
    num3 *= num1 * num2;
    QVERIFY(num3 == "20762936122929888116068405550279299956640101675030592995600");
    num3 *= 0;
    QVERIFY(num3 == 0);
    num3 = 1;
    num3 *= -1234567890;
    QVERIFY(num3 == -1234567890);
    num3 *= "-12345678909876543210";
    QVERIFY(num3 == "15241578762383784111263526900");
}

void arithmetictests::arithmeticAssignmentDivisionTest() {
    BigInt num1, num2, num3;
    num1 = "1695235400303";
    num2 = "-14409349785097830054018446630";
    num3 = "99609344092229394637577667754049630552571016118837570372569130682";

    num3 /= num1;
    QVERIFY(num3 == "58758414362055909808086078831411583704925762083687648");

    num3 /= num2;

    QVERIFY(num3 == "-4077797765921675738706461");
    num3 /= num2 / num1;
    QVERIFY(num3 == 479745944);
    num3 /= num1;
    QVERIFY(num3 == 0);

    num3 = "15241578762383784111263526900";
    num3 /= -1234567890;
    QVERIFY(num3 == "-12345678909876543210");
    num3 /= "-12345678909876543210";
    QVERIFY(num3 == 1);
}

void arithmetictests::arithmeticAssignmentModuloTest() {
    BigInt num1, num2, num3;
    num1 = "82548281880706855287";
    num2 = "-3093004007127403784763865131496495744552";
    num3 = "28759936859007420850030703143893813386234625466713870488148000919";

    num3 %= num2;
    QVERIFY(num3 == "2998899812449910677529571999817489505831");

    num2 %= num1;
    QVERIFY(num2 == "-23415035301048583249");
    num3 %= num1;
    QVERIFY(num3 == "66666005575090474406");
    num1 %= num3;
    QVERIFY(num1 == "15882276305616380881");
    num2 %= num1;
    QVERIFY(num2 == "-7532758995432202368");

    num3 = "459084894176556768517930341954189452458611284176831884451259";
    num3 %= -1032535817;
    QVERIFY(num3 == 192792682);

    num3 = "459084894176556768517930341954189452458611284176831884451259";
    num3 %= "7930435512290528311470664857140269665";
    QVERIFY(num3 == "4828359958287405771596693425686847994");
}

void arithmetictests::binaryArithmeticWithIntStrBigTest() {
    const long long FLOOR_SQRT_LLONG_MAX = 3037000499;

    std::random_device generator;
    // uniform distribution of numbers from -3037000499 to 3037000499:
    std::uniform_int_distribution<long long> distribution((-FLOOR_SQRT_LLONG_MAX),
                                                          (FLOOR_SQRT_LLONG_MAX));
    for (size_t i = 0; i < 200; i++) {
        BigInt integer1 = distribution(generator);
        BigInt integer2 = distribution(generator);
        if (integer1 == 0 or integer2 == 0) {   // prevent division by zero
            i--;
            continue;
        }

        BigInt big_int1 = integer1;
        BigInt big_int2 = integer2;
        std::string integer2_str = integer2.getString();

        // addition:
        BigInt sum = integer1 + integer2;
        QVERIFY(big_int1 + big_int2     == sum);
        QVERIFY(big_int1 + integer2     == sum);
        QVERIFY(big_int1 + integer2_str == sum);
        QVERIFY(big_int2     + big_int1 == sum);
        QVERIFY(integer2     + big_int1 == sum);
        QVERIFY(integer2_str + big_int1 == sum);

        // subtraction:
        BigInt difference = integer1 - integer2;
        QVERIFY(big_int1 - big_int2     == difference);
        QVERIFY(big_int1 - integer2     == difference);
        QVERIFY(big_int1 - integer2_str == difference);
        QVERIFY(big_int2     - big_int1 == -difference);
        QVERIFY(integer2     - big_int1 == -difference);
        QVERIFY(integer2_str - big_int1 == -difference);

        // multiplication:
        BigInt product = integer1 * integer2;
        QVERIFY(big_int1 * big_int2     == product);
        QVERIFY(big_int1 * integer2     == product);
        QVERIFY(big_int1 * integer2_str == product);
        QVERIFY(big_int2     * big_int1 == product);
        QVERIFY(integer2     * big_int1 == product);
        QVERIFY(integer2_str * big_int1 == product);

        // division:
        BigInt quotient = integer1 / integer2;
        BigInt quotient_reciprocal = integer2 / integer1;
        QVERIFY(big_int1 / big_int2     == quotient);
        QVERIFY(big_int1 / integer2     == quotient);
        QVERIFY(big_int1 / integer2_str == quotient);
        QVERIFY(big_int2     / big_int1 == quotient_reciprocal);
        QVERIFY(integer2     / big_int1 == quotient_reciprocal);
        QVERIFY(integer2_str / big_int1 == quotient_reciprocal);

        // modulo:
        BigInt remainder = integer1 % integer2;
        BigInt remainder_reciprocal = integer2 % integer1;
        QVERIFY(big_int1 % big_int2     == remainder);
        QVERIFY(big_int1 % integer2     == remainder);
        QVERIFY(big_int1 % integer2_str == remainder);
        QVERIFY(big_int2     % big_int1 == remainder_reciprocal);
        QVERIFY(integer2     % big_int1 == remainder_reciprocal);
        QVERIFY(integer2_str % big_int1 == remainder_reciprocal);
    }
}

void arithmetictests::binaryArithmeticWith0Test() {
    BigInt num;
    num = "1234567890123456789012345678901234567890";

    QVERIFY(num + 0 == num);
    QVERIFY(num - 0 == num);
    QVERIFY(num * 0 == 0);

    QVERIFY(0 + num ==  num);
    QVERIFY(0 - num == -num);
    QVERIFY(0 * num == 0);
    QVERIFY(0 / num == 0);
    QVERIFY(0 % num == 0);
}

void arithmetictests::binaryArithmeticAddSubTest() {
    BigInt num1 = 1234;
    BigInt num2 = 56789;
    BigInt num3 = 101112;
    BigInt num4 = 13141516;
    QVERIFY(num1 + num2 + num3 + num4 == 13300651);
    QVERIFY(num1 - num2 + num3 + num4 == 13187073);
    QVERIFY(num1 + num2 - num3 + num4 == 13098427);
    QVERIFY(num1 + num2 + num3 - num4 == -12982381);
    QVERIFY(num1 - num2 - num3 + num4 == 12984849);
    QVERIFY(num1 - num2 + num3 - num4 == -13095959);
    QVERIFY(num1 + num2 - num3 - num4 == -13184605);
    QVERIFY(num1 - num2 - num3 - num4 == -13298183);
}

void arithmetictests::binaryArithmeticDivModTest() {
    BigInt num1 = static_cast<unsigned long long>(313233343536373839);
    BigInt num2 = static_cast<unsigned long long>(212223242526272829);
    BigInt num3 = static_cast<unsigned long long>(111213141516171819);
    BigInt num4 = static_cast<unsigned long long>(12345678910);

    QVERIFY(num1 * num2 / num3 % num4 == BigInt(static_cast<unsigned long long>(9021418300)));
    QVERIFY(num1 * num2 % num3 / num4 == BigInt(static_cast<unsigned long long>(6392448)));
    QVERIFY(num1 / num2 * num3 % num4 == BigInt(static_cast<unsigned long long>(6635659579)));
    QVERIFY(num1 / num2 % num3 * num4 == BigInt(static_cast<unsigned long long>(12345678910)));
    QVERIFY(num1 % num2 * num3 / num4 == "909925710857417206643517");
    QVERIFY(num1 % num2 / num3 * num4 == 0);
}

void arithmetictests::binaryArithmeticBigTest() {
    BigInt num1, num2;
    num1 = "964793941351798875130890128898086485681241334814868066116469822595"
           "687598448053045508928021048387109439448430241206886222949385913536"
           "17836411623804682393334501579397617644828334316728238955353058394264";
    num2 = "542060529704217132357214772959828385120983424339263541090375634996"
           "368065850294867611447397165152437998796443501783597014569840671683"
           "13210331303669787440432347511637996556242776045622241233979589718916";
    QVERIFY(num1 + num2 == "15068544710560160074881049018579148708022247591541"
                           "31607206845457592055664298347913120375418213539547438244873742990"
                           "48323751922658521931046742927474469833766849091035614201071110362"
                           "350480189332648113180");

    num1 = "-19456862453160453307638071783433388649631926064367472120354136295"
           "908610671862754051755238831363430525061125138089083649263206899106"
           "180343851589754547911836910916517013121829987691413708752682939530093";
    num2 = "816553076977620349766958416466042124954414412870431261355772588173"
           "273756816453377871361812881641294479548961786166170884010949495342"
           "27956257833623792756494659469534082561332606937935191051654689548416";
    QVERIFY(num1 + num2 == "62198445244601581669057769863170823845809515222675"
                           "65401522312252141876500978258373538094245680069892289377104052753"
                           "34391378880504280476124062438692448446577485530170694395026192465"
                           "21482298971750018323");

    num1 = "239051672644169719606760847726448849722952349353674737803305086175"
           "964897566266679588060951437665097321115985305673099530769568871522"
           "45499107716567135414777307777041355408432721268223982670393229830408";
    num2 = "-45388635689554372889456021208799010297399750799135284700297465410"
           "290594446637518031367847208953611686547054464297776583106699748315"
           "71906644184297446268805816895836929754710634789080915280425559423001";
    QVERIFY(num1 + num2 == "19366303695461534671730482651764983942555259855453"
                           "94531030076207656743031196291615566931042287114856345689308413753"
                           "22947662869123206735924635322696891459714908812044256537220864791"
                           "43067389967670407407");

    std::string sum;
    num1 = BigInt::bigPow10(1525);
    num2 = BigInt::bigPow10(2750);
    sum = "1" + std::string(2750 - 1525 - 1, '0') + "1" + std::string(1525, '0');
    QVERIFY(num1 + num2 == sum);

    num1 = BigInt::bigPow10(3875);
    num2 = -BigInt::bigPow10(5490);
    sum = "-" + std::string(5490 - 3875, '9') + std::string(3875, '0');
    QVERIFY(num1 + num2 == sum);

    num1 = BigInt::bigPow10(19876);
    num2 = BigInt::bigPow10(23450);
    sum = "1" + std::string(23450 - 19876 - 1, '0') + "1" + std::string(19876, '0');
    QVERIFY(num1 + num2 == sum);
}

void arithmetictests::binaryArithmeticSubtractionBigTest() {
    BigInt num1, num2;
    num1 = "244519519883208981610410491992186770044882615922116562728872847144"
           "421092065072619855932223524830025832896873758619497075789940851207"
           "16036623521081847217851760412478092335656686950878812602818804060088";
    num2 = "-94425733811917851828605532625703702955076512086024371088350998261"
           "196757834829702575354045148220569953447106949397940559706260326388"
           "28634363448939208619936099903329996345089935704304349196301998955360";
    QVERIFY(num1 - num2 == "33894525369512683343901602461789047299995912800814"
                           "09338172238454056178498999023224312862686730505957863439807080174"
                           "37635496201177595446709869700210558377878603158080886807466226551"
                           "83161799120803015448");

    num1 = "-68985388257152076898307722398568069114569275150745660636500453122"
           "361335250374573735886985878878256091550832525534234783139806339978"
           "04531841900565455099200079685136917576702910555227461601790724376924";
    num2 = "727483877648813365652533679594255899405397184767522058008426131998"
           "131529490549312516017332620262440606302137189946954415157145256899"
           "53212281719565428986155762468758034363469065219343576930733687283864";
    QVERIFY(num1 - num2 == "-7964692659059654425508414019928239685199664599182"
                           "67718644926585120492864740923886251904318499140696697852969715481"
                           "18919829695159687757744123620130884085355842153894951940171975774"
                           "571038532524411660788");

    num1 = "925303738374648618488768260990584709987661046412988919780698877679"
           "650011360190156923243086758248351549060110046601233139482977571723"
           "68389150744548489610998029282638268114361253166438240576351224508584";
    num2 = "523739575704971221852123690170162065549469315720636849353841858576"
           "794958912896691529594741418267238468975328418156471008089785554092"
           "454742205154244706320735384145817395506750071592361784501457672552";
    QVERIFY(num1 - num2 == "92006634261759890627024702408888308933216635325578"
                           "25512871604590938820617710611900079471393440656791643703567624196"
                           "68429402079716182759344085393942449046772938984924507188545030948"
                           "45878791849766836032");

    std::string difference;
    num1 = BigInt::bigPow10(3126);
    num2 = BigInt::bigPow10(2097);
    difference = std::string(3126 - 2097, '9') + std::string(2097, '0');
    QVERIFY(num1 - num2 == difference);

    num1 = BigInt::bigPow10(3875);
    num2 = -BigInt::bigPow10(5490);
    difference = "1" + std::string(5490 - 3875 - 1, '0') + "1" + std::string(3875, '0');
    QVERIFY(num1 - num2 == difference);

    num1 = BigInt::bigPow10(35088);
    num2 = BigInt::bigPow10(27149);
    difference = std::string(35088 - 27149, '9') + std::string(27149, '0');
    QVERIFY(num1 - num2 == difference);
}

void arithmetictests::binaryArithmeticMultiplicationBigTest(){
BigInt num1, num2;
    num1 = "1234567890";
    num2 = "12345678901234567890";
    QVERIFY(num1 * num2 == "15241578751714678875019052100");

    num1 = "74795969103554554996215276693934490847811844274620";
    num2 = "-52918576235658446609301827261047318817814919806509";
    QVERIFY(num1 * num2 == "-39580961931264054802943979852752588263328417515871"
        "01538786510224257493862421103501026851769859501580");

    num1 = "9582518950379800614306095260421646856475999938972041161410754824718"
        "8530515989621711174263184271175858137696144827610415473041959151743248"
        "4229896130736";
    num2 = "7183178499181562107254471437293951674461271038850005413302515662375"
        "5697355361810132505715688137025455771038053164648324034388264089738986"
        "9764487550589";
    QVERIFY(num1 * num2 == "688329440923680539900273976992795654211511681990024"
        "3223280952847744060245431221201608457153558098391226973463787572086498"
        "8286684146085609255199499546372688486729372202884271671750355256222081"
        "1343929322816987582816790738952977665859931342689201004021415981394352"
        "574892370071759247880576536253157803504");

    num1 = BigInt::bigPow10(1525);
    num2 = BigInt::bigPow10(2750);
    QVERIFY(num1 * num2 == BigInt::bigPow10(4275));

    num1 = BigInt::bigPow10(3875);
    num2 = - BigInt::bigPow10(5490);
    QVERIFY(num1 * num2 == - BigInt::bigPow10(9365));

    num1 = BigInt::bigPow10(19876);
    num2 = BigInt::bigPow10(23450);
    QVERIFY(num1 * num2 == BigInt::bigPow10(43326));

    num1 = BigInt::bigPow10(19876) + 1;
    num2 = BigInt::bigPow10(23450);
    QVERIFY(num1 * num2 == BigInt::bigPow10(43326) + BigInt::bigPow10(23450));
}

void arithmetictests::binaryArithmeticBaseDivTest() {
    BigInt num;
    num = "1234567890123456789012345678901234567890";

    QVERIFY(num /  1 ==  num);
    QVERIFY(num / -1 == -num);

    QVERIFY((num - 1) / num == 0);
}

void arithmetictests::binaryArithmeticBigDivTest() {
    BigInt num1, num2;
        num1 = "12345678901234567890";
        num2 = "1234567890";
        QVERIFY(num1 / num2 == BigInt(static_cast<unsigned long long>(10000000001)));

        num1 = "74795969103554554996215276693934490847811844274620";
        num2 = "-5291857623565844660930182726104731881781491980";
        QVERIFY(num1 / num2 == -14134);

        num1 = "9582518950379800614306095260421646856475999938972041161410754824718"
            "8530515989621711174263184271175858137696144827610415473041959151743248"
            "42298961307365134004615";
        num2 = "7183178499181562107254471437293951674461271038850005413302515662375"
            "5697355361810132505715688137025455771038053164648324034388264089738986"
            "976448753";
        QVERIFY(num1 / num2 == "133402211172555");

        num1 = "-920132912302829612061902393145744233945758297736906406054053889535"
            "6968429805690068413076628064294801864511568551589205855316992620853084"
            "3219577396774861536705894326785721164938367932913682323736670444";
        num2 = "-126173815845557317670134103088446550114061753703252550511788939308"
            "82979573617430830373800";
        QVERIFY(num1 / num2 == "729258211092795635494143745485389681543083349270759"
            "3708106029725015022394056069241322168656324094196515329458910");

        num1 = BigInt::bigPow10(456);
        num2 = BigInt::bigPow10(123);
        QVERIFY(num1 / num2 == BigInt::bigPow10(333));

        num1 = BigInt::bigPow10(2749);
        num2 = BigInt::bigPow10(1523);
        QVERIFY(num1 / num2 == BigInt::bigPow10(1226));

        num1 = -BigInt::bigPow10(5483);
        num2 = BigInt::bigPow10(3877);
        QVERIFY(num1 / num2 == -BigInt::bigPow10(1606));

        num1 = BigInt::bigPow10(23459);
        num2 = BigInt::bigPow10(19867);
        QVERIFY(num1 / num2 == BigInt::bigPow10(3592));
}

void arithmetictests::binaryArithmeticBaseModTest() {
    BigInt num;
    num = "1234567890123456789012345678901234567890";

    QVERIFY(num %  1 == 0);
    QVERIFY(num % -1 == 0);

    QVERIFY(num %  num == 0);
    QVERIFY(num % -num == 0);
}

void arithmetictests::binaryArithmeticBigModTest() {
    BigInt num1, num2;
        num1 = "12345678909876543210123456789";
        num2 = 1234567890;
        QVERIFY(num1 % num2 == 819);

        num1 = "-74795969103554554996215276693934490847811844274620";
        num2 = "529185762356584466093018272610473188178149";
        QVERIFY(num1 % num2 == "-404625987744468732097714762347932921438432");

        num1 = "9582518950379800614306095260421646856475999938972041161410754824718"
            "8530515989621711174263184271175858137696144827610415473041959151743248"
            "42298961307365134004615";
        num2 = "7183178499181562107254471437293951674461271038850005413302515662375"
            "5697355361810132505715688137025455771038053164648324034388264089738986";
        QVERIFY(num1 % num2 == "502008140524007203128630082431770583307845442935791"
            "9728555544083411210356832664053040147221561393576626728850496195492998"
            "0314390096754463");

        num1 = "920132912302829612061902393145744233945758297736906406054053889535"
            "6968429805690068413076628064294801864511568551589205855316992620853084"
            "3219577396774861536705894326785721164938367932913682323736670444";
        num2 = "-126173815845557317670134103088446550114061753703252550511788939308"
            "82979573617430830373800";
        QVERIFY(num1 % num2 == "103737999458960727172146109955280604488347153612922"
            "63695257182569105701287999976696112444");

        num1 = BigInt::bigPow10(456);
        num2 = BigInt::bigPow10(123);
        QVERIFY(num1 % num2 == 0);

        num1 = -BigInt::bigPow10(6789);
        num2 = BigInt::bigPow10(2345);
        QVERIFY(num1 % num2 == 0);

        num1 = BigInt::bigPow10(23450);
        num2 = BigInt::bigPow10(19876);
        QVERIFY(num1 % num2 == 0);

}

void arithmetictests::incrementTest() {
    BigInt num;
    QVERIFY(num++ == 0);
    QVERIFY(num == 1);
    QVERIFY(++num == 2);
    QVERIFY(num == 2);

    num = -1000000000;
    QVERIFY(num++ == -1000000000);
    QVERIFY(num == -999999999);
    QVERIFY(++num == -999999998);
    QVERIFY(num == -999999998);
}

void arithmetictests::decrementTest() {
    BigInt num;
    QVERIFY(num-- == 0);
    QVERIFY(num == -1);
    QVERIFY(--num == -2);
    QVERIFY(num == -2);

    num = -1000000000;
    QVERIFY(num-- == -1000000000);
    QVERIFY(num == -1000000001);
    QVERIFY(--num == -1000000002);
    QVERIFY(num == -1000000002);
}

void arithmetictests::relationalOperatorsTest() {
    std::vector<BigInt> big_nums = {    // manually sorted vector of BigInts
        BigInt("-123456789012345678901234567890123456"),
        BigInt("-2134567890"),
        BigInt("-1324567890"),
        BigInt("-1234567890"),
        BigInt("-234567890"),
        BigInt("-134567890"),
        0,
        BigInt("134567890"),
        BigInt("234567890"),
        BigInt("1234567890"),
        BigInt("1324567890"),
        BigInt("2134567890"),
        BigInt("123456789012345678901234567890123456")
    };

    for (size_t i = 0; i < big_nums.size(); i++) {
        for (size_t j = 0; j < big_nums.size(); j++) {
            if (i == j)
                QVERIFY(big_nums[i] == big_nums[j]);
            if (i != j)
                QVERIFY(big_nums[i] != big_nums[j]);
            if (i < j)
                QVERIFY(big_nums[i] < big_nums[j]);
            if (i > j)
                QVERIFY(big_nums[i] > big_nums[j]);
            if (i <= j)
                QVERIFY(big_nums[i] <= big_nums[j]);
            if (i >= j)
                QVERIFY(big_nums[i] >= big_nums[j]);
        }
    }

}

void arithmetictests::relationalOperatorsBigIntsTest() {
    BigInt num = 1234567890;

    //Left operand: BigInt, right operand: integer

    QVERIFY((num < 1234567890) == false);
    QVERIFY((num > 1234567890) == false);
    QVERIFY((num <= 1234567890) == true);
    QVERIFY((num >= 1234567890) == true);
    QVERIFY((num == 1234567890) == true);
    QVERIFY((num != 1234567890) == false);

    //Left operand: integer, right operand: BigInt

    QVERIFY((1234567890 < num) == false);
    QVERIFY((1234567890 > num) == false);
    QVERIFY((1234567890 <= num) == true);
    QVERIFY((1234567890 >= num) == true);
    QVERIFY((1234567890 == num) == true);
    QVERIFY((1234567890 != num) == false);

    //Left operand: BigInt, right operand: string
    QVERIFY((num < "1234567890") == false);
    QVERIFY((num > "1234567890") == false);
    QVERIFY((num <= "1234567890") == true);
    QVERIFY((num >= "1234567890") == true);
    QVERIFY((num == "1234567890") == true);
    QVERIFY((num != "1234567890") == false);

    //Left operand: string, right operand: BigInt

    QVERIFY(("1234567890" < num) == false);
    QVERIFY(("1234567890" > num) == false);
    QVERIFY(("1234567890" <= num) == true);
    QVERIFY(("1234567890" >= num) == true);
    QVERIFY(("1234567890" == num) == true);
    QVERIFY(("1234567890" != num) == false);
}

void arithmetictests::shiftingTest() {
    BigInt num1, num2;
    num1 = "2";
    num2 = "4";

    QVERIFY((num1 >> 1) == 1);
    QVERIFY((num2 >> 1) == 2);

    num1 = BigInt::bigPow10(57542);
    num2 = num1;

    num1 <<= 1;
    QVERIFY((num1 >>= 1) == num2);

    num1 <<= 15;
    QVERIFY((num1 >>= 15) == num2);
}

void arithmetictests::binTest() {
    BigInt num, num2;
    int n1, n2;

    for (int i = 0 ; i < 1000; ++i) {
        num = n1 = rand();
        num2 = n2 = rand();

        QVERIFY((num | num2) == (n1 | n2));
        QVERIFY((num & num2) == (n1 & n2));
        QVERIFY((num ^ num2) == (n1 ^ n2));
        QVERIFY((~num2) == (~n2));

        QVERIFY((num | n2) == (n1 | num2));
        QVERIFY((num & n2) == (n1 & num2));
        QVERIFY((num ^ n2) == (n1 ^ num2));
        QVERIFY((~num) == (~n1));

        QVERIFY((n2 | num) == (num2 | n1));
        QVERIFY((n2 & num) == (num2 & n1));
        QVERIFY((n2 ^ num) == (num2 ^ n1));

    }

}

void arithmetictests::testOperators() {
    BigInt num1;

    QVERIFY(num1.sizeBytes() == 0);
    num1 = 1;

    QVERIFY(num1.sizeBytes() == sizeof (intMpz));

    num1++;
    QVERIFY(num1.sizeBytes() == sizeof (intMpz));

    num1+= 0xFF;
    QVERIFY(num1.sizeBytes() == sizeof (intMpz));

    num1 += std::numeric_limits<intMpz>::max();
    num1 += std::numeric_limits<intMpz>::max();

    QVERIFY(num1.sizeBytes() == sizeof (intMpz) * 2);

    num1 = 1;
    QVERIFY(num1.sizeBytes() == sizeof (intMpz));
    QVERIFY(num1.sizeType() == sizeof (intMpz) * 2);


}


QTEST_APPLESS_MAIN(arithmetictests)

#include "tst_arithmetictests.moc"
