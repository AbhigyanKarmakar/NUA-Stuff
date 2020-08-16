
class DummyClass
{
public:
	DummyClass() { std::cout << "\nInstance Created!!!"; }
	~DummyClass() { std::cout << "\nInstance Destroyed!!!"; }
};

int size = 1;

void foo(void)
{
	//auto ptr = new DummyClass[size];
	//Stuff
	//delete[] ptr;
}


void UsingUniquePtr(void)
{
	auto ArrayNewStyle = std::make_unique<DummyClass[]>(size);
	//auto arr = std::unique_ptr<DummyClass[]>(new DummyClass[size]);

	std::cout << "\nQuitting Function UniquePtr Function";
}

std::shared_ptr<DummyClass[]> SharedArray3;
void UsingSharedPtr(void)
{
	auto SharedArray = std::make_shared<DummyClass[]>(size);

	auto SharedArray2 = SharedArray;
	SharedArray3 = SharedArray;

	std::cout << "\nQuitting Function SharedPtr Function";
}

std::weak_ptr<DummyClass[]> ArrayWeak;

void UsingWeakPtr(void)
{
	auto ArrayNewStyle = std::make_shared<DummyClass[]>(size);
	ArrayWeak = ArrayNewStyle;
	std::cout << "\nBOOL STATUS OF WEAK PTR (EXPIRED?) : " << ArrayWeak.expired();

	std::cout << "\nQuitting Function WeakPtr Function";
}

int main()
{
	return 0;
}


