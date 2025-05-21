#ifndef IVISITOR_H
#define IVISITOR_H

class IVisitor
{
public:
    virtual ~IVisitor() = default;

    virtual void visit(class Bill &) = 0;
    virtual void visit(class Cart &) = 0;
    virtual void visit(class KhoHang &) = 0;
    virtual void visit(class UserManagement &) = 0;
    virtual void visit(class BillManagement &) = 0;
};

class GetMoneyVisitor : public IVisitor
{
public:
    GetMoneyVisitor() = default;
    ~GetMoneyVisitor() override = default;

    void visit(Bill &) override;
    void visit(Cart &) override;
};
#endif