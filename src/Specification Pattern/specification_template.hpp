#pragma once

#include <memory>

template <class T>
class ISpecification
{
public:
	virtual ~ISpecification() = default;
	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const = 0;
	virtual ISpecification<T>* And(const ISpecification<T>& Other) const = 0;
	virtual ISpecification<T>* AndNot(const ISpecification<T>& Other) const = 0;
	virtual ISpecification<T>* Or(const ISpecification<T>& Other) const = 0;
	virtual ISpecification<T>* OrNot(const ISpecification<T>& Other) const = 0;
	virtual ISpecification<T>* Not() const = 0;
};

template <class T>
class CompositeSpecification : public ISpecification<T>
{
public:
	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override = 0;

	virtual ISpecification<T>* And(const ISpecification<T>& Other) const override;
	virtual ISpecification<T>* AndNot(const ISpecification<T>& Other) const override;
	virtual ISpecification<T>* Or(const ISpecification<T>& Other) const override;
	virtual ISpecification<T>* OrNot(const ISpecification<T>& Other) const override;
	virtual ISpecification<T>* Not() const override;
};

template <class T>
class AndSpecification final : public CompositeSpecification<T>
{
public:
	const ISpecification<T>& Left;
	const ISpecification<T>& Right;

	AndSpecification(const ISpecification<T>& InLeft, const ISpecification<T>& InRight)
		: Left(InLeft),
		  Right(InRight) { }

	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override
	{
		return Left.IsSatisfiedBy(Candidate) && Right.IsSatisfiedBy(Candidate);
	}
};

template <class T>
ISpecification<T>* CompositeSpecification<T>::And(const ISpecification<T>& Other) const
{
	return new AndSpecification<T>(*this, Other);
}

template <class T>
class AndNotSpecification final : public CompositeSpecification<T>
{
public:
	const ISpecification<T>& Left;
	const ISpecification<T>& Right;

	AndNotSpecification(const ISpecification<T>& InLeft, const ISpecification<T>& InRight)
		: Left(InLeft),
		  Right(InRight) { }

	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override
	{
		return Left.IsSatisfiedBy(Candidate) && !Right.IsSatisfiedBy(Candidate);
	}
};

template <class T>
class OrSpecification final : public CompositeSpecification<T>
{
public:
	const ISpecification<T>& Left;
	const ISpecification<T>& Right;

	OrSpecification(const ISpecification<T>& InLeft, const ISpecification<T>& InRight)
		: Left(InLeft),
		  Right(InRight) { }

	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override
	{
		return Left.IsSatisfiedBy(Candidate) || Right.IsSatisfiedBy(Candidate);
	}
};

template <class T>
class OrNotSpecification final : public CompositeSpecification<T>
{
public:
	const ISpecification<T>& Left;
	const ISpecification<T>& Right;

	OrNotSpecification(const ISpecification<T>& InLeft, const ISpecification<T>& InRight)
		: Left(InLeft),
		  Right(InRight) { }

	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override
	{
		return Left.IsSatisfiedBy(Candidate) || !Right.IsSatisfiedBy(Candidate);
	}
};

template <class T>
class NotSpecification final : public CompositeSpecification<T>
{
public:
	const ISpecification<T>& Other;

	NotSpecification(const ISpecification<T>& InOther)
		: Other(InOther) { }

	virtual bool IsSatisfiedBy(const std::shared_ptr<T>& Candidate) const override
	{
		return !Other.IsSatisfiedBy(Candidate);
	}
};

template <class T>
ISpecification<T>* CompositeSpecification<T>::AndNot(const ISpecification<T>& Other) const
{
	return new AndNotSpecification<T>(*this, Other);
}

template <class T>
ISpecification<T>* CompositeSpecification<T>::Or(const ISpecification<T>& Other) const
{
	return new OrSpecification<T>(*this, Other);
}

template <class T>
ISpecification<T>* CompositeSpecification<T>::OrNot(const ISpecification<T>& Other) const
{
	return new OrNotSpecification<T>(*this, Other);
}

template <class T>
ISpecification<T>* CompositeSpecification<T>::Not() const
{
	return new NotSpecification<T>(*this);
}