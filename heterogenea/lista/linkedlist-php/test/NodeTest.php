<?php 

declare(strict_types=1);

use Lista\class\Node;

use PHPUnit\Framework\TestCase;

class NodeTest extends TestCase {

    public function testGetValue() : void
    {

        $node = new Node(10);

        $this->assertEquals(10, $node->getValue());

    }

    public function testSetValueInt() : void
    {

        $node = new Node(10);

        $node->setValue(25);
        
        $this->assertEquals(25, $node->getValue());
        
    }

    public function testSetValueFloat() : void
    {

        $node = new Node(10);

        $node->setValue(2.55);
        
        $this->assertEquals(2.55, $node->getValue());
        
    }

    public function testSetValueString() : void
    {

        $node = new Node(10);

        $node->setValue(25);
        
        $node->setValue("Testeeeee");

        $this->assertEquals("Testeeeee", $node->getValue());

    }

    public function testGetNextNull() : void
    {

        $node = new Node(10);

        $this->assertNull($node->getNext());

    }

    public function testGetNextNode() : void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $this->assertEquals($node1, $node2->getNext());

    }

    public function testSetNextNull() : void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $node2->setNext(null);

        $this->assertNull($node2->getNext());

    }

    public function testSetNextNode() : void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $node3 = new Node(99);

        $node2->setNext($node3);

        $this->assertEquals($node3, $node2->getNext());

    }

}


?>