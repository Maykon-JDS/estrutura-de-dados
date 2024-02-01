<?php 

declare(strict_types=1);

use PHPUnit\Framework\TestCase;

use Lista\class\StandartLinkedListStrategy;

use Lista\class\Node;

class StandartLinkedListStrategyTest extends TestCase {
    
    public function testGetHeadNull() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();
    
        $this->assertNull($linkedlist->getHead());
    
    }

    public function testAddHeadNodeInt() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);

        $node = new Node(10);

        $this->assertEquals($node, $linkedlist->getHead());

    }

    public function testAddHeadNodeFloat() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(1.8);

        $node = new Node(1.8);

        $this->assertEquals($node, $linkedlist->getHead());

    }

    public function testAddHeadNodeString() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead("Teste");

        $node = new Node("Teste");

        $this->assertEquals($node, $linkedlist->getHead());

    }

    public function testAddHeadThree() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $node1 = new Node(10);
        
        $node2 = new Node(1.8, $node1);

        $node3 = new Node("Teste", $node2);

        $linkedlist->addHead(10);

        $this->assertEquals($node1, $linkedlist->getHead());

        $this->assertEquals(Null, $linkedlist->getHead()->getNext());
        
        $linkedlist->addHead(1.8);

        $this->assertEquals($node2, $linkedlist->getHead());

        $this->assertEquals($node1, $linkedlist->getHead()->getNext());

        $linkedlist->addHead("Teste");

        $this->assertEquals($node3, $linkedlist->getHead());

        $this->assertEquals($node2, $linkedlist->getHead()->getNext());

    }

    public function testGetTailNull() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();
    
        $this->assertNull($linkedlist->getTail());

    }

    public function testAddTailHeadOneNode() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addTail(10);

        $node = new Node(10);
    
        $this->assertEquals($node,$linkedlist->getTail());

        $this->assertEquals($node,$linkedlist->getHead());

    }

    public function testAddTailHeadFourNode() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(20);

        $linkedlist->addHead(1.8);

        $linkedlist->addHead("Teste");

        $linkedlist->addTail(10);

        $node = new Node(10);
    
        $this->assertEquals($node,$linkedlist->getTail());

    }

    public function testAddTailNodeInt() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addTail(10);

        $node = new Node(10);

        $this->assertEquals($node, $linkedlist->getTail());

    }

    public function testAddTailNodeFloat() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addTail(1.8);

        $node = new Node(1.8);

        $this->assertEquals($node, $linkedlist->getTail());

    }

    public function testAddTailNodeString() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addTail("Teste");

        $node = new Node("Teste");

        $this->assertEquals($node, $linkedlist->getTail());

    }

    public function testAddTailThree() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $node1 = new Node(10);
        
        $node2 = new Node(1.8);

        $node3 = new Node("Teste");

        $linkedlist->addTail(10);

        $this->assertEquals($node1, $linkedlist->getTail());

        $this->assertEquals(Null, $linkedlist->getTail()->getNext());

        $node1->setNext($node2);
        
        $linkedlist->addTail(1.8);

        $this->assertEquals($node2, $linkedlist->getTail());

        $this->assertEquals(Null, $linkedlist->getTail()->getNext());

        $node2->setNext($node3);

        $linkedlist->addTail("Teste");

        $this->assertEquals($node3, $linkedlist->getTail());

        $this->assertEquals(Null, $linkedlist->getTail()->getNext());

    }

    public function testSizeNull() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $this->assertEquals(0, $linkedlist->size());

    }

    public function testSizeFull() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);
        
        $linkedlist->addHead(1.8);
        
        $linkedlist->addHead("Teste");

        $this->assertEquals(3, $linkedlist->size());

    }

    public function testGetIndexNull() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();
    
        $this->assertNull($linkedlist->getIndex(0));
    
    }

    public function testGetIndexFirstNode() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);

        $node1 = new Node(10);
    
        $this->assertEquals($node1, $linkedlist->getIndex(0));
    
    }

    public function testGetIndexNode() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);
        
        $linkedlist->addHead(20);

        $linkedlist->addHead("Teste");
        
        $linkedlist->addHead(3.5);
        
        $linkedlist->addHead(98);

        $node3 = new Node(10);
        
        $node2 = new Node(20, $node3);
        
        $node1 = new Node("Teste",  $node2);
    
        $this->assertEquals($node1, $linkedlist->getIndex(2));
    
    }

    public function testGetIndexNotFound() : void
    {
    
        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);
        
        $linkedlist->addHead(20);

        $linkedlist->addHead("Teste");
        
        $linkedlist->addHead(3.5);
        
        $linkedlist->addHead(98);
    
        $this->assertNull($linkedlist->getIndex(5));
    
    }

    public function testPopHeadNull() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->popHead();

        $this->assertNull($linkedlist->getHead());

    }

    public function testPopHeadOneNode() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(10);

        $linkedlist->popHead();

        $this->assertNull($linkedlist->getHead());

    }

    public function testPopHeadThreeNodes() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(90.45);

        $linkedlist->addHead("Teste");

        $linkedlist->addHead(10);

        $linkedlist->popHead();

        $node2 = new Node(90.45);

        $node1 = new Node("Teste", $node2);

        $this->assertEquals($node1, $linkedlist->getHead());

    }
    
    public function testPopTailNull() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->popTail();

        $this->assertNull($linkedlist->getTail());

    }

    public function testPopTailOne() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(90.45);

        $linkedlist->popTail();

        $this->assertNull($linkedlist->getHead());

        $this->assertNull($linkedlist->getTail());

    }

    public function testPopTailThreeNodes() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(90.45);

        $linkedlist->addHead("Teste");

        $linkedlist->addHead(10);

        $linkedlist->popTail();

        $node1 = new Node("Teste", Null);

        $node2 = new Node(10, $node1);

        $this->assertEquals($node1, $linkedlist->getTail());

        $this->assertEquals($node2, $linkedlist->getHead());

    }

    public function testPopIndexNull() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->popIndex(1);

        $this->assertNull($linkedlist->getHead());

    }

    public function testPopIndexOne() : void
    {

        $linkedlist = new StandartLinkedListStrategy();

        $linkedlist->addHead(90.45);

        $linkedlist->addHead("Teste");

        $linkedlist->addHead(10);

        $linkedlist->popIndex(1);

        $node1 = new Node(90.45, Null);

        $node2 = new Node(10, $node1);

        $this->assertEquals($node2, $linkedlist->getHead());

        $this->assertEquals($node1, $linkedlist->getHead()->getNext());

    }



}


?>