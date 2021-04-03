#include <iostream>

#include <gtest/gtest.h>

#include <core/ent/ent.tpp>

#include <core/ent/ent_vect.tpp>

#include <core/ent/ent_storage.tpp>

#include <core/cmp/cmp.tpp>

#include <core/cmp/cmp_storage.tpp>

#include <core/ent/ent.tpp>

#include <core/ent/ent_base.tpp>

#include <core/gtx/gtx.tpp>

TEST(Test, example)
{
    struct CMP_TEST_t : Moon::Core::Component_t<CMP_TEST_t>
    {
        int data;
        CMP_TEST_t(Moon::Alias::EntityId eid, int data) : Moon::Core::Component_t<CMP_TEST_t>(eid), data{data} {}
        ~CMP_TEST_t() override {}
    };

    struct ENT_TEST_1_t : Moon::Core::Entity_t<ENT_TEST_1_t>
    {
        ENT_TEST_1_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<ENT_TEST_1_t>(eid) {}
        ~ENT_TEST_1_t(){}
    };

    struct ENT_TEST_2_t : Moon::Core::Entity_t<ENT_TEST_2_t>
    {
        ENT_TEST_2_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<ENT_TEST_2_t>(eid) {}
        ~ENT_TEST_2_t(){}
    };

    struct GTX_TEST_1_t : Moon::Core::GameContext_t<ENT_TEST_1_t>
    {
    };

    auto gtx = GTX_TEST_1_t();

    auto &e1 = gtx.addEntity<ENT_TEST_1_t>();

    auto &e2 = gtx.addEntity<ENT_TEST_2_t>();

    auto *e_1 = gtx.getEntityById<ENT_TEST_2_t>(2);

    auto &c1 = gtx.addComponentById<ENT_TEST_1_t, CMP_TEST_t>(e1.eid, 5);

    gtx.destroyEntityById<ENT_TEST_1_t>(e1.eid);

    EXPECT_EQ(0, gtx.getComponents<CMP_TEST_t>().size());
    EXPECT_EQ(0, gtx.getEntities<ENT_TEST_1_t>().size());
    EXPECT_EQ(1, gtx.getEntities<ENT_TEST_2_t>().size());

    EXPECT_EQ(1, CMP_TEST_t::getComponentType());
    EXPECT_EQ(1, ENT_TEST_1_t::getEntityType());
    EXPECT_EQ(2, ENT_TEST_2_t::getEntityType());
    EXPECT_EQ(c1.getComponentType(), CMP_TEST_t::getComponentType());
}


TEST(Test, example_1)
{
    struct ENT_TEST_2_t : Moon::Core::Entity_t<ENT_TEST_2_t>
    {
        ENT_TEST_2_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<ENT_TEST_2_t>(eid) {}
        ~ENT_TEST_2_t(){}
    };

    struct ENT_TEST_1_t : Moon::Core::Entity_t<ENT_TEST_1_t>
    {
        ENT_TEST_1_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<ENT_TEST_1_t>(eid) {}
        ~ENT_TEST_1_t(){}
    };

    auto storage = Moon::Core::EntityStorage_t();

    auto e1 = storage.createEntity<ENT_TEST_1_t>(1);
    auto& vect_1 = storage.getEntities<ENT_TEST_1_t>();
    EXPECT_EQ(1, vect_1.size());
    struct NewEntity : Moon::Core::Entity_t<NewEntity>
    {
        NewEntity(Moon::Alias::EntityId eid)
        : Moon::Core::Entity_t<NewEntity>(eid)
        {
            //TODO
        }
    
        ~NewEntity(){}
    };
}